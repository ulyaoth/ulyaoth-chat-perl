#!/usr/bin/perl

if ($command eq '/clean' && $level < $staff_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}

opendir(rooms,"$root/online/rooms/");

@allmail = readdir(rooms);

closedir(rooms);

$x = 0;

foreach $s (@allmail){

if ($s ne "." && $s ne "..") {

$x++; 

unlink ("$root/online/rooms/$s");

open (r, ">>$root/online/rooms/$s");

print r "<b>*** rooms cleared by operator <b>$DATA{'n'}</b>. $fulltime </b><br>\n<br>\n<br>\n<br>\n<br>\n<br>\n";

close(r);


   }

}


$errors = " total of $x rooms cleared.";



return $errors;



exit;







