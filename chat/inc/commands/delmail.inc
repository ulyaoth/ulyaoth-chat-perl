#!/usr/bin/perl


if($level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



@del = split(/\s+/, $DATA{'msg'});

@del[1] =~ s/[^\w]//g;

if(length(@del[1]) < 10 or length(@del[1]) > 10){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}


open(DEL,"$root/mail/$realnick.txt");
 
flock(DEL,1);

@dell = <DEL>;

close(DEL);

open(DEL2,">$root/mail/$realnick.txt");

flock(DEL2,2);

$f = 0;

foreach $mail(@dell){

if($mail !~ /@del[1]/){

   print DEL2 $mail;

  }


}

close(DEL2);

############################## PRINT CMAIL AGAIN ########################################################


dbmopen(%MAIL,"$root/opspreferences/$realnick",0777);

$MAIL{'mail_inbox'} = $MAIL{'mail_inbox'} - 1;

$MAIL{'mail_new'} = "0";

$MAIL{'mail_status'} = "*** <b>CMAIL</b> Total: <b>$MAIL{'mail_inbox'}</b>. New: <b>0</b>. Please use /mail to read cmail and set your options, /mail [nick] to send.";

dbmclose(%MAIL);


print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(CHECKCMAIL,"$root/mail/$realnick.txt");

@checkcmail = <CHECKCMAIL>;

foreach $line(@checkcmail){

($c1,$c2,$c3)=split(/\|\"\'\|/,$line);


$c3 =~ s/^\s+//ig;

$c3 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;


print "<b>OPTIONS: <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/delmail+$c1\">DEL</a> | <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/igmail+$c2\">Block CMAIL</a> | <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/wait+$c2\">Add WAIT</a></b><br>\n $c3\n\n";


}

require "$root/inc/check_pm.inc";


require "$root/inc/print_footer.inc";


exit;

