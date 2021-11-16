#!/usr/bin/perl





if ($command eq '/mail' && $level < 1){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;



}





@mail  = split(/\s+/,$DATA{'msg'});



$mailtext = $DATA{'msg'};



$mailtext =~ s/^\/mail//;



$mailtext =~ s/^\s+//;



$mailtext =~ s/^@mail[1]//;



@mail[1] =~ s/[^\w]//g;



@mail[1]=substr(@mail[1],0,14);







if(@mail[1] && !@mail[2]){



$errors = " Syntax: /mail [nick] [message].";



return $errors;



exit;



}







if(!@mail[1]){



open(CM,"$root/mail/$realnick.txt");



@cc = <CM>;



close(CM);



$h = 0;



foreach$j(@cc){



$h++;



}





if($h < 1){



$errors = " <b>CMAIL</b> Total: <b>0</b>. New: <b>0</b>. Please use /mail [nick] to send.";



return $errors;



exit;



} 





dbmopen(%MAIL,"$root/opspreferences/$realnick",0777);



$MAIL{'mail_inbox'} = $h;



$MAIL{'mail_new'} = "0";



$MAIL{'mail_status'} = "*** <b>CMAIL</b> Total: <b>$h</b>. New: <b>0</b>. Please use /mail to read cmail and set your options, /mail [nick] to send.";



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





}



if(!-e "$root/ops/ops/@mail[1]"){



$errors = " Error , user <b>@mail[1]</b> doesn't have an $title id.";



return $errors;



exit;



}



open(MAILIG,"$root/mail/igmail/@mail[1].txt");



@igmail = <MAILIG>;



close(MAILIG);



foreach $line(@igmail){



chop($line);



if($line eq $realnick){



$errors = " Error , Ops <b>@mail[1]</b> is ignoring your Chat Mails.";



return $errors;



exit;



}}





dbmopen(%MAIL,"$root/opspreferences/@mail[1]",0777);



$MAIL{'mail_inbox'}++;



$MAIL{'mail_new'}++;



$MAIL{'mail_status'} = "*** <b>CMAIL</b> Total: <b>$MAIL{'mail_inbox'}</b>. <font color=\"red\">New: <b>$MAIL{'mail_new'}</b>.</font> Please use /mail to read cmail and set your options, /mail [nick] to send.";



dbmclose(%MAIL);





for (0..9) { $cid .= pack("C",65+int(rand(25.99))); }



open(CMAIL,">>$root/mail/@mail[1].txt");



flock(CMAIL,2);



print CMAIL "$cid\|\"\'\|$realnick\|\"\'\| <!-- $cid --> <b>$opsid \*$realnick\*</b><font size=\"1\" color=\"$iback\">i</font> ($ip) $fulltime.<br> $scolor$mailtext$ecolor<p>\n"; 



close(CMAIL); 





$errors = " Cmail sent to Ops <b>@mail[1]</b> Time: $fulltime:<br> $mailtext";



return $errors;



exit;







