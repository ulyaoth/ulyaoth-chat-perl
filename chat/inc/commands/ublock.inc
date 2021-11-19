#!/usr/bin/perl


if ($command eq '/ublock' && $level < $staff_rank){

 
$errors = " Error, command $command not recognized, please use /help for a list of commands.";


return $errors;



exit;

}


unlink ("$root/online/noproxy/proxy.txt");


$b = 0;

$k = 0;

opendir(BOOT,"$root/online/banned/");

@dirlists = readdir(BOOT);

closedir(BOOT);

foreach $i(@dirlists){

if($i ne '.' && $i ne '..'){

$b++;

unlink ("$root/online/banned/$i.db");

	}
}

opendir(BOOT,"$root/online/kicked/");

@dirlist = readdir(BOOT);

closedir(BOOT);

foreach $i(@dirlist){

if($i ne '.' && $i ne '..'){

$k++;

unlink ("$root/online/kicked/$i.db");

	}
}


$msg_action = "<!-- $time --> *** UBLOCK: Operator <b>$DATA{'n'}</b> flushed ban directory ($b bans). Flushed kick directory ($k kicks). NoProxy = OFF.<br>\n";


require "$root/inc/msg_action.inc";


undef $msg_action;


$errors = " Ublock successful. Flushed ban directory ($b bans). Flushed kick directory ($k kicks). NoProxy = OFF.";


return $errors;


exit;