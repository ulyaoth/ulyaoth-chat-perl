#!/usr/bin/perl

if ($command eq '/reboot' && $level >= 100){


opendir(BOOT,"$root/online/");


@dirlists = readdir(BOOT);


closedir(BOOT);

foreach $i(@dirlists){


opendir(A,"$root/online/$i/");

@e = readdir(A);


closedir(A);

foreach $b(@e){

unlink("$root/online/$i/$b.db");


}





}


$errors = " $title Server is being rebooted.";

return $errors;

exit;

}


if($command eq '/reboot' && $level < 100){


$errors = " Command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}