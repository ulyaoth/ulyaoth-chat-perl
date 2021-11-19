#!/usr/bin/perl


$basedir = "/srv/ulyaoth/chat/public/upload";


@send = split(/\s+/,$DATA{'msg'});

unless(@send[2]){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}

if(!-e "$root/online/users/@send[1].db" || !-e "$basedir/@send[2]") {

$errors = " Error, user <b>@send[1]</b> is not online or uploaded file doesn\'t exist.";

return $errors;

exit;

}

open(SENT,">>$root/online/pm/@send[1].txt");

flock(SENT,2);

print SENT "<!-- $time --> <b>*** User $DATA{'n'} is sending you a file</b>, use Netscape or IE to download file <a href=\"\/up\/@send[2]\" target=_blank><b>@send[2]</b></a>. ( $title does not guarentee and is inno way responsible for any files transferred by individuals in the chat in any way \/ content could be un-suitable for underage parties or damage your hardwarde or software ).<br>\n";



close(SENT);


$errors = " File sent to user <b>@send[1]</b> --> <b>@send[2]</b>.";

return $errors;


exit;