#!/usr/bin/perl



if ($command eq '/clear' && $level >= 12 && @messsage[1] ne '-' && $deopped ne 1){ 



@clear = split(/\s+/, $DATA{'msg'});


@clear[1] =~ s/[^\w\Á\È\Ê\Ë\Ì\Í\Î\Ï\ä\Ñ\Ó\Ô\Õ\Ö\Ø\Ù\Ú\Û\Ý\Þ\ß\á\ã\ä\æ\í\À\Â\Ã\Ä\Å\Æ\Ç\É\Ð\Ö\Ò\à\å\æ\ç\è\é\ê\ë\ì\í\î\ï]//g;

@clear[1]=substr(@clear[1],0,13);


if(length(@clear[1]) < 3 && !-e "$root/online/users/@clear[1].db"){


$errors = " Syntax: /clear [text].";

return $errors;

exit;



}else{



open(ROOMSS2,"$root/online/rooms/$room.txt");

 

flock(ROOMSS2,1);



@roomss2 = <ROOMSS2>;



close(ROOMSS2);



open(BUFFER,">>$root/clearlog/$time_file.txt");



flock(BUFFER,2);



print BUFFER "<hr><b>$DATA{'n'}</b>($realnick) in room $room. Time: $fulltime<hr>\n";



open(ROOMSS3,">$root/online/rooms/$room.txt");



 flock(ROOMSS3,2);



$f = 0;



foreach $i(@roomss2){

$b = $i;

$i =~ s/<([^>]|\n)*>//g;

$i =~ s/^\s+//ig;

if($i =~ /^\[$DATA{'n'}\]/ && $i =~ /@clear[1]/i or $i =~ /^\* $DATA{'n'}/ && $i =~ /@clear[1]/i){



$f++;



}



if($i !~ /@clear[1]/i or $i =~ /^\[$DATA{'n'}\]/ && $level < $comm_rank or $i =~ /^\* $DATA{'n'}/ && $level < $comm_rank or $i =~ /^\*\*\*/ && $level < $comm_rank){



   print ROOMSS3 $b;



  }else{



print BUFFER $b;



}





}



print BUFFER "<hr>\n";



close(BUFFER);


if($level < $comm_rank){

print ROOMSS3 "<!--servermsg--> *** <b>$DATA{'n'}</b> has partially cleared the room.<br>\n";

}

close(ROOMSS3);





$msg_action = "<!-- $time --> *** CLEARING: By Ops <B>$DATA{'n'}</b> ($realnick) in room $room (@clear[1]).<br>\n";



require "$root/inc/msg_action.inc";



undef $msg_action;









if($f > 0 && $level < $comm_rank){



$errors = " Error, you are not allowed to clear your own messages.";



return $errors;



}else{



$bypass = 1;



return $bypass;



}



exit;





}



}



#############################################################################





if ($command eq '/clear' && $level >= 12 && @messsage[1] eq '-' && $deopped ne 1){





if($level >= 30){



open(FULLCLEAR,">$root/online/rooms/$room.txt");



flock(FULLCLEAR,2);




print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<br>\n";

print FULLCLEAR "<!--servermsg--> *** <b>$DATA{'n'}</b> has cleared the room.<br>\n";

close(FULLCLEAR);

$msg_action = "<!-- $time --> *** FULL CLEARING: Operator <B>$DATA{'n'}</b> ($realnick) in room <b>$room</b>.<br>\n";

require "$root/inc/msg_action.inc";

undef $msg_action;


$bypass = 1;



return $bypass;



exit;



}else{





$errors = " Syntax: /clear [text].";



return $errors;



exit;



}



}







if($command eq '/clear' && $level >= 12 && @messsage[1] eq '-' && $deopped == 1){

                



        $errors = " Sorry, you are not allowed to use this command.";



return $errors;



exit;



        }



if ($command eq '/clear' && $level >= 12 && @messsage[1] ne '-' && $deopped == 1){

                



  $errors = " Sorry, you are not allowed to use this command.";



return $errors;



exit;



        }





if ($command eq '/clear' && $level < 12){

                



        $errors = " Command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;



        }