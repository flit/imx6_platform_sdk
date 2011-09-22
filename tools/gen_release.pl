#!/usr/bin/perl -w

#Below is a description of arguments required for this perl script
#ARGV[0]: Path to the SDK config folder e.g:/home/user/diag-sdk/configs
#ARGV[1]: Path to the Base SDK folder e.g:/home/user/diag-sdk
#ARGV[2]: Path to the SDK release folder e.g:/home/user/diag-sdk/imx_sdk_release
#ARGV[3]: SOC Name e.g:mx53, mx61,...
#ARGV[4]: Board Name e.g:ard, smd...

use File::Copy;
use File::Find;
use File::Path;

#Create friendly names
my $sdk_conf_path = "$ARGV[0]";
my $sdk_base_path = "$ARGV[1]";
my $release_path = "$ARGV[2]";
my $imx_name = "$ARGV[3]";
my $board_name = "$ARGV[4]";

#Open the configuration input file
my $in_file = "$sdk_conf_path/$imx_name$board_name.conf";

if (!(open (INP_FH, $in_file))) {
    # Try if configuration file is common for all boards for this target
    $in_file = "$sdk_conf_path/$imx_name.conf";
    open INP_FH, $in_file or die "Can't read source file $in_file: $!\n";
}

#Make sure we are at the SDK Base directory
chdir($sdk_base_path) or die "Can't change directory: $!\n";

#Delete the release directory if it exists
rmtree($release_path);
#Create the release directory
mkpath($release_path);

# Read in the file one line at a time
while (<INP_FH>) {
    s/#.*//;             # ignore comments by erasing them
    next if /^(\s)*$/;  # skip blank lines
    my $line = $_;
    #Delete trailing newline
    chomp($line);
    copy_release_files($line);

    #Get the Sub-directories list
    my @elements = split(/\//, $line);
    pop(@elements); # Remove the last entry as we already processed it

    my $num_of_elems = scalar @elements;

    #Maintain an array for the directory tree
    for ($k=0; $k < $num_of_elems; $k++) {
        my $src_dir;

        for ($h=0; $h <= $k; $h++) {
            $src_dir .= "$elements[$h]/";
        }

        #List of sub-directories
        push (@sub_dir_elements, $src_dir);
    }
}

#copy all the files related, covering all the sub directories.
#copy_release_files("src/sdk");
#copy_release_files("src/sdk/$tested_module");
#my @elements = list_sub_dirs("src/sdk/$tested_module");
#foreach my $e (@elements)
#{
#    push (@sub_dir_elements, $e);
#}
#Remove duplicate entries in the sub-directories list
my %rem_dup;
@rem_dup{ @sub_dir_elements } = ();
my @sub_dir_elements_out = keys %rem_dup;

my $num_of_sub_dirs = scalar @sub_dir_elements_out;

#Copy the directory tree
for ($l=0; $l < $num_of_sub_dirs; $l++) {
    my $src_file;
    #List of sub-directories
    $src_file =pop (@sub_dir_elements_out);
    copy_release_files($src_file);
}

#Copy the include folder
copy_release_files("src/include");
copy_release_files("src/include/$imx_name");
copy_release_files("src/cortex_a9");
#copy_release_files("tools/linux");
#copy_release_files("tools/windows");

#Create the tools and rvd directory
mkpath("$release_path/tools/rvd");
copy("$sdk_base_path/tools/rvd/$imx_name$board_name\_init.inc","$release_path/tools/rvd/$imx_name$board_name\_init.inc");

copy("$sdk_base_path/tools/build_sdk","$release_path/tools/build_sdk");
chmod 0755, "$release_path/tools/build_sdk";
copy("$sdk_base_path/tools/gen_make.pl","$release_path/tools/gen_make.pl");
chmod 0755, "$release_path/tools/gen_make.pl";

copy("$sdk_base_path/makefile.in", "$release_path/makefile.in");
copy("$sdk_base_path/make.rules", "$release_path/make.rules");
copy("$sdk_base_path/make.def", "$release_path/make.def");

#Create the configs directory
mkpath("$release_path/configs");
copy("$sdk_base_path/configs/$imx_name$board_name.conf", "$release_path/configs/$imx_name$board_name.conf");

exit 2;

sub list_sub_dirs {
	my $input = shift;
	opendir(DIR, $input) or die "Cannot open directory $input:$!\n";
	my @dirs = readdir(DIR);
	closedir(DIR);
	foreach my $dir (@dirs) {
		if(-d "$sdk_base_path/$input/$dir") {
			if(($dir ne ".") && ($dir ne "..")) {
				push(@dir_list, "$input/$dir");	
				list_sub_dirs("$input/$dir/");
			}
		}
	}
	return (@dir_list); 
}

# Copy files from the folder passed in as an argument into destination release folder
sub copy_release_files {
    my $src_path = shift;
    my $targetdir = "$release_path/$src_path";
    my $file_perm_mode = 0644;

    mkpath( $targetdir ) if not -e $targetdir;
    opendir(DIR, $src_path) or die "Cannot open directory$src_path:$!\n";
    my @src_list = grep { -f "$src_path/$_" } readdir(DIR);
    closedir(DIR);

    foreach my $src (@src_list) {
       	copy("$sdk_base_path/$src_path/$src", "$targetdir/$src");
       	chmod $file_perm_mode, "$targetdir/$src";
    }

}
