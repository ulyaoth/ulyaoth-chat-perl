#!/usr/bin/perl



if ($command eq '/mops' && $level < $comm_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;



}





@mail  = split(/\s+/,$DATA{'msg'});


$mailtext = $DATA{'msg'};



$mailtext =~ s/^\/mops//;



$mailtext =~ s/^\s+//;



if(!@mail[1]){



$errors = " Syntax: /mops [message].";



return $errors;



exit;



}




opendir(ALLMAIL,"$root/online/users/");

 @allmail = readdir(ALLMAIL);

 closedir(ALLMAIL);



foreach $s(@allmail){



if ($s ne "." && $s ne ".."){

$s =~ s/.db//;

dbmopen(%OPS,"$root/online/users/$s",0777);

if($OPS{'level'} >= 1){

$n++;

&send_mail($s);


dbmclose(%OPS);

}

dbmclose(%OPS);

}
}




sub send_mail{

my($mailops) = @_;



open(PRIVE,">>$root/online/pm/$mailops.txt");


flock(PRIVE,2);

print PRIVE "<!-- $time --> $scolor<A HREF=\"javascript:m('$DATA{'n'}')\"><B>\*$DATA{'n'}\* </a> TO ALL OPS ONLINE </b>($ip) $mailtext$ecolor<br>\n";


close(PRIVE);



}



$errors = " Message sent to <b>$n</b> Operators currently online:<br> $mailtext";



return $errors;



exit;







