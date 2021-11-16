#!/usr/bin/perl

if ($command eq '/icq2' && $level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}


$DATA{'icq_message'} = substr($DATA{'icq_message'},0,300);


$DATA{'icq'} =~ s/\D//ig;


$DATA{'icq_message'} =~ s/^\s+//ig;

$DATA{'icq_message'} =~ s/\s+\s+/ /ig;


if(!$DATA{'icq'} or !$DATA{'icq_message'}){

$errors = " Error, you left one more fields empty.";

return $errors;

exit;

}


    open(MAIL,"|$sendmail -t");
    print MAIL "To: $DATA{'icq'}\@pager.icq.com\n";
    print MAIL "From: $DATA{'n'}\@ulyaoth.com ($DATA{'n'})\n";
    print MAIL "Message from: $DATA{'n'}\n\n$DATA{'icq_message'}\n";
    print MAIL "-" x 6 . "\n";
    print MAIL "*This message has been sent from chat.ulyaoth.com*\n";
    print MAIL "-" x 6 . "\n";
    close(MAIL);

$errors = "ICQ message has been sent to <b>$DATA{'icq'}</b> <b>|</b> <a href=\"http:\/\/wwp.icq.com\/scripts\/contact.dll?msgto=$DATA{'icq'}\"><img border=\"0\" width=\"44\" height=\"14\" alt=\" ICQ: $DATA{'icq'}\" src=\"http:\/\/wwp.icq.com\/scripts\/online.dll?icq=$DATA{'icq'}&amp\;img=1\"></a><b> |</b> :\n<br>$DATA{'icq_message'}\n";

return $errors;


exit;


