#!/usr/bin/perl



 

if ($command eq '/ann' && $level < $admin_rank){

                

 $errors = "Error, command $command not recognized, please use /help for a list of commands.";



 return $errors;



exit;



       }









@ann = split(/\s+/,$DATA{'msg'});



$aann = $DATA{'msg'};



$aann =~ s/^\/ann//;





if(!@ann[1]){



$errors = " Syntax: /ann [message].";



return $errors;



exit;





}



for (0..9) { $annid .= pack("C",65+int(rand(25.9999))); }



open(LOGINANN,">>$root/boards/loginann.txt");



flock(LOGINANN,2);



print LOGINANN "$annid\|\"\'\|<!-- $annid --> <b>$realnick</b><font size=\"1\" color=\"$iback\">i</font> ($ip) on $fulltime<br> $aann<p>\n";



close(LOGINANN);





$errors = " Time: $fulltime. Login announcement placed: $aann";



return $errors;



exit;



        