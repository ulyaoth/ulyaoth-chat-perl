#!/usr/bin/perl


if ($command eq '/lock' && $level >= 1){

foreach $key(@rooms){

if($key eq $room){

$bypass = 1;

return $bypass;

exit;}

}

open(LOCK,">$root/online/locked/$room.txt");

print LOCK "$DATA{'n'}\|\"\'\|$realnick\|\"\'\|$ip\|\"\'\|$fulltime";

close(LOCK);


open(LOCKEDROOM,">>$root/online/rooms/$room.txt");

flock(LOCKEDROOM,2);

print LOCKEDROOM "<!--servermsg--> *** Location <B>$room</B> has been locked by <B>$DATA{'n'}</B>.<br>\n";

close(LOCKEDROOM);

$bypass = 1;

return $bypass;

exit;

 }

if ($command eq '/lock' && $level < 1){
                

        $errors = " Command $command not recognized, please use /help for a list of commands.";

return $errors;

}
