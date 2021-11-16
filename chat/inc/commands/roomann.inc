#!/usr/bin/perl


if ($command eq '/roomann' && $level < $staff_rank){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";


 return $errors;

exit;

       }



@roomann = split(/\s+/,$DATA{'msg'});

unless(@roomann[1]){

$errors = " Syntax: /roomann [message].";

return $errors;

exit;

}

$DATA{'msg'} =~ s/^\/roomann//ig;

$DATA{'msg'} =~ s/^\s+//ig;


foreach $rum(@rooms){

open(R,">>$root/online/rooms/$rum.txt");

flock(R,2);

print R "<p>$scolor<b>*** Server Message: $DATA{'msg'}</b>$ecolor<p>\n";

close(R);

}


$errors = " Message posted.";

return $errors;

exit;


        