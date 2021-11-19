#!/usr/bin/perl


if ($command eq '/opsann' && $level < $max_staff_rank){

                
$errors = "Error, command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;


}

@ann = split(/\s+/,$DATA{'msg'});

unless(@ann[2]){

$errors = " Syntax: /opsann [message].";

return $errors;

exit;
}



$DATA{'msg'} =~ s/^\/opsann//ig;

open(FIL,">$root/boards/opsann.txt");

flock(FILE,2);

print FIL "<b>*** $DATA{'msg'}</b>";

close(FIL);

$errors = " Time: $fulltime. Private login announcement for operators posted: $DATA{'msg'}.";

return $errors;

exit;