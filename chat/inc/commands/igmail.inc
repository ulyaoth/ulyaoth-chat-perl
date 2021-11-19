#!/usr/bin/perl







if($command eq '/igmail' && $level < 1){





$errors = " Error, command $command not recognized, please use /help for a list of commands.";





}







@igmail  = split(/\s+/,$DATA{'msg'});



@igmail[1]=substr(@igmail[1],0,14);





if(@igmail[1] eq ''){



open(WWAIT,"$root/mail/igmail/$realnick.txt");



@wwa = <WWAIT>;



close(WWAIT);



$errors = " Syntax: /igmail [nick] to add. /igmail - [nick] to remove.<br> Current List: @wwa";



return $errors;



exit;





}







if(@igmail[1] eq '-' && @igmail[2] eq ''){





unlink ("$root/mail/igmail/$realnick.txt");





$errors = " Ignore Mail List flushed.";



return $errors;



exit;





}





if(@igmail[1] eq '-' && @igmail[2] ne ''){




 open(IGM,"$root/mail/igmail/$realnick.txt");



@igm = <IGM>;



close(IGM);

$r = 0;



open(IGM2,">$root/mail/igmail/$realnick.txt");



  foreach $i(@igm){



chop($i);



  if($i ne @igmail[2]){



   print IGM2 "$i\n";



  }else{



$r++;

}

 



}



close(IGM2);



if($r == 0){


$errors = " Error, user <b>@igmail[2]</b> not found.";



}else{





$errors = " User <b>@igmail[2]</b> removed from Ignore Mail List.";



}



return $errors;

exit;









}









if(!-e "$root/ops/ops/@igmail[1].db"){





$errors = " Error, user <b>@igmail[1]</b> doesn't have an $title id.";



return $errors;



exit;







}



open(MAILIG,"$root/mail/igmail/$realnick.txt");



@igmaail = <MAILIG>;



close(MAILIG);



foreach $line(@igmaail){



chop($line);



if($line eq @igmail[1]){



$errors = " Error  user <b>@igmail[1]</b> is already on your Ignore Mail List.<br> Current List: @igmaail";



return $errors;



exit;



}}





open(IGNOREMAIL,">>$root/mail/igmail/$realnick.txt");



print IGNOREMAIL "@igmail[1]\n";



close(IGNOREMAIL);





$errors = " User <b>@igmail[1]</b> added to Ignore Mail List.";



return $errors;



exit;