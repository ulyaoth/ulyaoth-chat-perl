#!/usr/bin/perl



if ($command eq '/opsmail' && $level < $staff_rank){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;



}





@mail  = split(/\s+/,$DATA{'msg'});


$mailtext = $DATA{'msg'};



$mailtext =~ s/^\/opsmail//;



$mailtext =~ s/^\s+//;



if(!@mail[1]){



$errors = " Syntax: /opsmail [message].";



return $errors;



exit;



}




opendir(ALLMAIL,"$root/ops/ops/");

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

dbmopen(%MAIL,"$root/opspreferences/$mailops",0777);



$MAIL{'mail_inbox'}++;



$MAIL{'mail_new'}++;



$MAIL{'mail_status'} = "*** <b>CMAIL</b> Total: <b>$MAIL{'mail_inbox'}</b>. <font color=\"red\">New: <b>$MAIL{'mail_new'}</b>.</font> Please use /mail to read cmail and set your options, /mail [nick] to send.";



dbmclose(%MAIL);


for (0..9) { $cid .= pack("C",65+int(rand(25.99))); }



open(CMAIL,">>$root/mail/$mailops.txt");



flock(CMAIL,2);



print CMAIL "$cid\|\"\'\|$realnick\|\"\'\| <!-- $cid --> <b>$opsid \*$realnick\* TO ALL OPS</b>  ($ip) $fulltime.<br> $scolor$mailtext$ecolor<p>\n"; 


undef $cid;

close(CMAIL); 

}



$errors = " Cmail sent to <b>$n</b> Ops  Time: $fulltime:<br> $mailtext";



return $errors;



exit;







