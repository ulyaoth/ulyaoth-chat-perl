#!/usr/bin/perl


if($command eq '/mkick' && $level < 12){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";


return $errors;

exit;        
}

if($deopped == 1){

$errors = " Sorry, you are not allowed to use this command.";
        
return $errors;

exit;
}



@mkick = split(/\s+/, $DATA{'msg'});


@mkick[1]=substr(@mkick[1],0,14);


$kickreason = $DATA{'msg'};

$kickreason =~ s/^\/mkick//ig;

$kickreason =~ s/^\s+//ig;

$kickreason =~ s/^@mkick[1]//ig;

$kickreason =~ s/^\s+//ig;


unless(@mkick[2]){

$errors = " Syntax: /mkick [nick] [reason].";
        
return $errors;

exit;

}

if(@mkick[1] eq $DATA{'n'}){

$errors = " Syntax: /mkick [nick] [reason].";
        
return $errors;

exit;

}



if(!-e "$root/online/users/@mkick[1].db") {

$errors = " Error, user <b>@mkick[1]</b> not found.";
        
return $errors;

exit;


}




dbmopen(%KICK,"$root/online/users/@mkick[1].db",0777);

$kick_level = $KICK{'level'};

$usr_agent = $KICK{'user_agent'};

$fuip = $KICK{'fullip'};

$mip = $KICK{'fullip'};

$renick = $KICK{'realnick'};

$usr_agent =~ s/[^\w]//g;

$kick_room = $KICK{'room'};

$fuip =~ s/[^\w]//g;

$kick_it = "$usr_agent$fuip";

dbmclose(%KICK);


if($kick_level >= 1){

$errors = " Error , <b>@mkick[1]</b> is an Ops, please use /kick instead.";

return $errors;


exit;
}


#################################################################################

$j = 0;

opendir(MKICK, "$root/online/users/");

@multi = readdir (MKICK);

      closedir(MKICK);

    foreach $multi (sort @multi) {


if ($multi ne '.' && $multi ne '..') {

$multi =~ s/.db//;

dbmopen(%USER,"$root/online/users/$multi",0777);

$multi_ip = $USER{'fullip'};

$multi_level = $USER{'level'}; 

dbmclose(%USER);

if($multi_ip == $mip && $multi_level < 1){

$j++;

open(KICKROOM,">>$root/online/rooms/$kick_room.txt");

flock(KICKROOM,2);

print KICKROOM "<!--servermsg--> *** Kick <b>$multi</b> by Ops <b>$DATA{'n'}</b> for ($kickreason).<br>\n";

close(KICKROOM);

unlink ("$root/online/pm/$multi.txt");
unlink ("$root/online/users/$multi");


                       }

next;

                 }

}

dbmopen(%KICKED,"$root/online/kicked/$kick_it.db",0777);

$KICKED{'kick'} = "*** KICK User <b>@mkick[1]</b><font size=\"1\" color=\"$iback\">i</font> ($renick) by <b>$DATA{'n'}</b> ($realnick) for reason ($kickreason).";

$KICKED{'time'} = $time;

dbmclose(%KICKED);

$msg_action = "<!-- $time -->*** MULTI KICK: Operator <B>$DATA{'n'} <font size=\"1\" color=\"$iback\">i</font>$online_time</b> ($realnick) ($room) has multi kicked $j <font size=\"1\" color=\"$iback\">i</font> <B>@mkick[1]</b> <font size=\"1\" color=\"$iback\">i</font> ($kick_room) for ($kickreason).<br>\n";

require "$root/inc/msg_action.inc";

undef $msg_action;


$errors = " Multi Kick <b>@mkick[1]</b> successful. <b>$j</b> users kicked out.";

return $errors;

exit;