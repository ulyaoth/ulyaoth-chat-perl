#!/usr/bin/perl



if ($command eq '/musers' && $level < $comm_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;



}





@mail  = split(/\s+/,$DATA{'msg'});


$mailtext = $DATA{'msg'};



$mailtext =~ s/^\/musers//;



$mailtext =~ s/^\s+//;



if(!@mail[1]){



$errors = " Syntax: /musers [message].";



return $errors;



exit;



}




opendir(ALLMAIL,"$root/online/users/");

 @allmail = readdir(ALLMAIL);

 closedir(ALLMAIL);



foreach $s(@allmail){



if ($s ne "." && $s ne ".."){

$n++;

$s =~ s/.db//;

&send_mail($s);


}
}




sub send_mail{

my($mailops) = @_;



open(PRIVE,">>$root/online/pm/$mailops.txt");


flock(PRIVE,2);

print PRIVE "<!-- $time --> $scolor<A HREF=\"javascript:m('$DATA{'n'}')\"><B>\*$DATA{'n'}\* </a> TO ALL USERS </b>($ip) $mailtext$ecolor<br>\n";


close(PRIVE);



}



$errors = " Message sent to <b>$n</b> users currently online:<br> $mailtext";



return $errors;



exit;