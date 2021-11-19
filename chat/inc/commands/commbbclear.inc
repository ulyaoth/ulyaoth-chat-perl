#!/usr/bin/perl



if ($command eq '/commbbclear' && $level < $comm_rank){
                

        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

        }

@bbclear = split(/\s+/, $DATA{'msg'});

@bbclear[1] =~ s/[^\w]//g;

@bbclear[1]=substr(@bbclear[1],0,10);

open(BB,"$root/boards/commbb.txt");
 
flock(BB,1);

@bb = <BB>;

close(BB);


open(NEWBB,">$root/boards/commbb.txt");

 flock(NEWBB,2);

foreach $i(@bb){


if($i !~ /@bbclear[1]/){

   print NEWBB $i;

  
}
}
close(NEWBB);


$errors = " Message successfuly deleted from committee bulletin board.";

return $errors;


exit;