#!/usr/bin/perl -w

#Below is a description of arguments required for this perl script
#ARGV[0]: Path to the SDK config folder e.g:/home/user/diag-sdk/configs
#ARGV[1]: Path to the Base SDK folder e.g:/home/user/diag-sdk
#ARGV[2]: SOC Name e.g:mx53, mx61, ...
#ARGV[3]: Board Name e.g:ard, smd, ...
#ARGV[4]: Test Name e.g:ipu, vpu, sdma, ...

use File::Find;
use File::Copy;

#Contents of the Makefile we plan to put in each directory
my $make_template=<<EOF;
include \$(PROJ_DIR)/make.def

MODULE := \$(shell basename \$(shell pwd))
MODULE_PREFIX := \$(subst /,_,\$(MODULE))
MODULE_OUT := \$(PROJ_OUT)/obj/\$(MODULE)

MODULE_C_FLAGS 	:=
MODULE_C_INCLUDES :=
MODULE_C_DEFINES 	:=

MODULE_A_FLAGS 		:=
MODULE_A_INCLUDES 	:=
MODULE_A_DEFINES 	:=

S_SRCS := \$(wildcard *.S)
C_SRCS := \$(wildcard *.c)
C_OBJS := \$(patsubst %c,%o,\$(C_SRCS))
S_OBJS := \$(patsubst %S,%o,\$(S_SRCS))
A_OBJS :=
MODULE_OBJS := \$(A_OBJS) \$(C_OBJS) \$(S_OBJS)
MODULE_OBJS := \$(addprefix \$(MODULE_OUT)/, \$(MODULE_OBJS))

SUB_DIRS := -=SUB_DIRS=-

.PHONY: dir \$(SUB_DIRS) all

dir:\$(SUB_DIRS) all

\$(SUB_DIRS):
	make -S -C \$@ dir

include \$(PROJ_DIR)/make.rules
EOF

#Create friendly names
my $sdk_conf_path = "$ARGV[0]";
my $sdk_base_path = "$ARGV[1]";
my $imx_name = "$ARGV[2]";
my $board_name = "$ARGV[3]";

#Open the configuration input file
my $in_file = "$sdk_conf_path/$imx_name$board_name.conf";
if (!(open (INP_FH, $in_file))) {
    # Try if the configuration file is common for all boards for this target
    $in_file = "$sdk_conf_path/$imx_name.conf";
    open INP_FH, $in_file or exit 1;
}

#Delete the Makefiles
find(\&Wanted, $sdk_base_path);

copy("$sdk_base_path/makefile.in", "$sdk_base_path/makefile") or die "File cannot be copied.";

# Read in the file one line at a time
while (<INP_FH>) {
    s/#.*//;                # ignore comments by erasing them
    next if /^(\s)*$/;  # skip blank lines
    $line = $_;
    #Delete trailing newline
    chomp($line);

    # Path to location of Makefile
    $out_file_name = "$line/makefile";

    # Write Makefile contents to the file
    open OUT_FH, "> $out_file_name" or die "Can't write to file $out_file_name: $!\n";
    $make_local_template = $make_template;
    $make_local_template =~ s/-=SUB_DIRS=-/ /g;
    print OUT_FH $make_local_template;

    #Get the Sub-directories list
    @elements = split(/\//, $out_file_name);
    pop(@elements); # Remove the Makefile name from the list

    $num_of_elems = scalar @elements;

    #Maintain a hash table for the directory tree
    for ($i=0; $i < $num_of_elems - 1; $i++) {
        my $path;
        #Hash key is the path where the Makefile will reside
        for ($j=0; $j <= $i; $j++) {
            $path .= "$elements[$j]/";
        }
        #Hash value is the list of sub-directories
        push @{ $dir_tree{$path} }, $elements[$i + 1];
    }
}

close OUT_FH;
# Write out Makefiles in the Sub directories
for $dir_tree_elem ( keys %dir_tree ) {
    #Remove duplicate entries in each hash entry
    my %saw;
    my @dir_tree_val = @{ $dir_tree{$dir_tree_elem} };
    @saw{ @dir_tree_val } = ();
    my @dir_tree_val_out = keys %saw;
    #Write sub_dirs list to the Make template
    my $sub_dirs = join(' ', @dir_tree_val_out);
    #print "$dir_tree_elem=$sub_dirs\n";
    $out_file_name = "$dir_tree_elem/makefile";
    open OUT_FH, "> $out_file_name" or die "Can't write to file $out_file_name: $!\n";
    $make_local_template = $make_template;
    $make_local_template =~ s/-=SUB_DIRS=-/$sub_dirs/g;
    # Write Makefile contents to the file
    print OUT_FH $make_local_template;
    close OUT_FH;
}
exit 2;

sub Wanted
{
    #Only operate on Makefiles
    /makefile$/ or return;
    unlink($File::Find::name);
}
