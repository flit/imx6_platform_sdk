#!/usr/bin/perl -w

#Below is a description of arguments required for this perl script
#ARGV[0]: Path to the SDK config folder e.g:/home/user/diag-sdk/configs
#ARGV[1]: Path to the Base SDK folder e.g:/home/user/diag-sdk
#ARGV[2]: Path to the SDK release folder e.g:/home/user/diag-sdk/imx_sdk_release
#ARGV[3]: SOC Name e.g:mx53, mx50, mx28...
#ARGV[4]: Board Name e.g:evk...
#ARGV[5]: test module name, for example SDMA, IPU, VPU ...

use File::Copy;
use File::Find;
use File::Path;

#Open the configuration input file
my $in_file = "$ARGV[0]/$ARGV[3]$ARGV[4].conf";

if (!(open (INP_FH, $in_file))) {
    # Try if configuration file is common for all boards for this target
    $in_file = "$ARGV[0]/$ARGV[3].conf";
    open INP_FH, $in_file or die "Can't read source file $in_file: $!\n";
}

#Make sure we are at the SDK Base directory
chdir($ARGV[1]) or die "Can't change directory: $!\n";

#Release dir name is derived from the input config filename
my $target_dir_name = "$ARGV[2]";

#Delete the release directory if it exists
rmtree($target_dir_name);
#Create the release directory
mkpath($target_dir_name);

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
copy_release_files("src/sdk");
copy_release_files("src/sdk/$ARGV[5]");
my @elements = list_sub_dirs("src/sdk/$ARGV[5]");
foreach my $e (@elements)
{
    push (@sub_dir_elements, $e);
}
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
copy_release_files("src/include/mx53");
copy_release_files("tools/linux");
copy_release_files("tools/windows");

copy("$ARGV[1]/makefile", "$target_dir_name/makefile");
copy("$ARGV[1]/make.rules", "$target_dir_name/make.rules");
copy("$ARGV[1]/make.def", "$target_dir_name/make.def");

exit 2;

sub list_sub_dirs {
	my $input = shift;
	opendir(DIR, $input) or die "Cannot open directory $input:$!\n";
	my @dirs = readdir(DIR);
	closedir(DIR);
	foreach my $dir (@dirs) {
		if(-d "$ARGV[1]/$input/$dir") {
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
    my $targetdir = "$target_dir_name/$src_path";
    my $file_perm_mode = 0755;

    mkpath( $targetdir ) if not -e $targetdir;
    opendir(DIR, $src_path) or die "Cannot open directory$src_path:$!\n";
    my @src_list = grep { -f "$src_path/$_" } readdir(DIR);
    closedir(DIR);

    foreach my $src (@src_list) {
       	copy("$ARGV[1]/$src_path/$src", "$targetdir/$src");
       	chmod $file_perm_mode, "$targetdir/$src";
    }

}

