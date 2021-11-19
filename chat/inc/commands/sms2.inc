#!/usr/bin/perl

if ($command eq '/sms2' && $level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}

$DATA{'sms_message'} = substr($DATA{'sms_message'},0,110);

if (!$DATA{'sms'} or !$DATA{'sms_message'}){

$errors = " Error, you left one or more fields empty.";

return $errors;

exit;

}



     open(MAIL,"|$sendmail -t");
    print MAIL "To: $DATA{'sms'}\@sms.tdm.dk, $DATA{'sms'}\@smsicq.com\n";
    print MAIL "From: $DATA{'n'}\@ulyaoth.com\n";
    print MAIL "Subject: $DATA{'n'}\n";
    print MAIL " $DATA{'sms_message'}\n\n";
    close(MAIL);


$errors = " SMS message has been sent to <b>| $DATA{'sms'} |</b>\n<br>$DATA{'sms_message'}\n";

return $errors;


exit;