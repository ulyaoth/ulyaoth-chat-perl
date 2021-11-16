#!/usr/bin/perl


if($level < 10){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;        

}

if(-e "$root/online/action/$DATA{'n'}.txt"){

unlink ("$root/online/action/$DATA{'n'}.txt");

$errors = "Logging <b>OFF</b>.";

return $errors;

exit;

}else{

open(LOG,">$root/online/action/$DATA{'n'}.txt");

print LOG "ON";

close(LOG);

$errors = " Logging enabled. Clear | Warnings | Kick | Ban.";

return $errors;

exit;

}



