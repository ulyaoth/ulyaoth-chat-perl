#!/usr/bin/perl


if ($command eq '/unlock' && $level >= 1){

   foreach $key(@rooms){

if($key eq $room){

$bypass = 1;

return $bypass;

exit;}

}

unlink ("$root/online/locked/$room.txt");

open(LOCKEDROOM,">>$root/online/rooms/$room.txt");

flock(LOCKEDROOM,2);

print LOCKEDROOM "<!--servermsg--> *** Location <B>$room</B> has been unlocked by <B>$DATA{'n'}</B>.<br>\n";

close(LOCKEDROOM);

$bypass = 1;

return $bypass;

exit;

 }

if ($command eq '/unlock' && $level < 1){
                

        $errors = " Command $command not recognized, please use /help for a list of commands.";

return $errors;

}
