#!/usr/bin/perl

if ($level < $admin_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}

@email = split(/\s+/, $DATA{'msg'});

if(!$DATA{'from'}){

$DATA{'from'} = $webmaster;

}

$DATA{'email_message'} = substr($DATA{'email_message'},0,500);

$DATA{'email_message'} =~ s/\s+\s+/ /ig;

$DATA{'email_message'} =~ s/^\s+//ig;

if(!$DATA{'email_message'}){

$errors = " Error, please input the email message.";

return $errors;

exit;

}

# mail comm

if(@email[1] eq "comm"){

opendir(dir,"$root/ops/ops/");

flock(dir,2);

@e = readdir(dir);

closedir(dir);

$c = 0;

foreach $o(@e){

if($o ne '.' && $o ne '..'){

$o =~ s/.db//ig;

dbmopen(%Z,"$root/ops/ops/$o",0777);

if($Z{'level'} >= $comm_rank && $Z{'level'} < $staff_rank){

$c++;

     open(MAIL,"|$sendmail -t");
    print MAIL "To: $Z{'email'}\n";
    print MAIL "From: $DATA{'from'} ($title)\n";
    print MAIL "Subject: $title Committee announcment\n";
    print MAIL "Dear $Z{'name'} ($o)\,\n\n\n";
    print MAIL "*** IMPORTANT MESSAGE TO ALL COMMITTEE MEMBERS ***\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "$DATA{'email_message'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "$title webmaster\n";
    close(MAIL);

sleep(1);

		}

dbmclose(%Z);

	}

}

$errors = " Email has been sent to <b>$c</b> $title committee members: <br>$DATA{'email_message'}\n";

return $errors;


exit;

}
#####################################################################################################################


# mail staff

if(@email[1] eq "staff"){

opendir(dir,"$root/ops/ops/");

flock(dir,2);

@e = readdir(dir);

closedir(dir);

$c = 0;

foreach $o(@e){

if($o ne '.' && $o ne '..'){

$o =~ s/.db//ig;

dbmopen(%Z,"$root/ops/ops/$o",0777);

if($Z{'level'} >= $staff_rank && $Z{'level'} < $admin_rank){

$c++;

     open(MAIL,"|$sendmail -t");
    print MAIL "To: $Z{'email'}\n";
    print MAIL "From: $DATA{'from'} ($title)\n";
    print MAIL "Subject: $title Staff Announcment\n";
    print MAIL "Dear $Z{'name'} ($o)\,\n\n\n";
    print MAIL "*** IMPORTANT MESSAGE TO ALL STAFF MEMBERS ***\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "$DATA{'email_message'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "$title webmaster\n";
    close(MAIL);

sleep(1);

		}
dbmclose(%Z);

	}

}

$errors = " Email has been sent to <b>$c</b> $title staff members: <br>$DATA{'email_message'}\n";

return $errors;


exit;

}
####################################################################################################

# mail deopped

if(@email[1] eq "deopped"){

opendir(dir,"$root/deopped/");

flock(dir,2);

@e = readdir(dir);

closedir(dir);

$c = 0;

foreach $o(@e){

if($o ne '.' && $o ne '..'){

$o =~ s/.db//ig;

dbmopen(%Z,"$root/ops/ops/$o",0777);


$c++;

     open(MAIL,"|$sendmail -t");
    print MAIL "To: $Z{'email'}\n";
    print MAIL "From: $DATA{'from'} ($title)\n";
    print MAIL "Subject: $title Announcment\n";
    print MAIL "Dear $Z{'name'} ($o)\,\n\n\n";
    print MAIL "*** IMPORTANT MESSAGE TO ALL DEOPPED MEMBERS ***\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "$DATA{'email_message'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "$title webmaster\n";
    close(MAIL);

sleep(1);

	dbmclose(%Z);	

	}

}

$errors = " Email has been sent to <b>$c</b> deopped $title members: <br>$DATA{'email_message'}\n";

return $errors;


exit;

}


####################################################################################################

# mail suspended

if(@email[1] eq "suspended"){

opendir(dir,"$root/suspend/");

flock(dir,2);

@e = readdir(dir);

closedir(dir);

$c = 0;

foreach $o(@e){

if($o ne '.' && $o ne '..'){

$o =~ s/.db//ig;

dbmopen(%Z,"$root/ops/ops/$o",0777);


$c++;

     open(MAIL,"|$sendmail -t");
    print MAIL "To: $Z{'email'}\n";
    print MAIL "From: $DATA{'from'} ($title)\n";
    print MAIL "Subject: $title Announcment\n";
    print MAIL "Dear $Z{'name'} ($o)\,\n\n\n";
    print MAIL "*** IMPORTANT MESSAGE TO ALL SUSPENDED OPERATORS ***\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "$DATA{'email_message'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "$title webmaster\n";
    close(MAIL);

sleep(1);

dbmclose(%Z);
		

	}

}

$errors = " Email has been sent to <b>$c</b> suspended $title members: <br>$DATA{'email_message'}\n";

return $errors;


exit;

}

####################################################################################################

# mail specified rank

if(@email[1] > 1 && @email[1] < 210){

opendir(dir,"$root/ops/ops/");

flock(dir,2);

@e = readdir(dir);

closedir(dir);

$c = 0;

foreach $o(@e){

if($o ne '.' && $o ne '..'){

$o =~ s/.db//ig;

dbmopen(%Z,"$root/ops/ops/$o",0777);

if($Z{'level'} == @email[1]){

$c++;

     open(MAIL,"|$sendmail -t");
    print MAIL "To: $Z{'email'}\n";
    print MAIL "From: $DATA{'from'} ($title)\n";
    print MAIL "Subject: $title Announcment\n";
    print MAIL "Dear $Z{'name'} ($o)\,\n\n\n";
    print MAIL "*** IMPORTANT MESSAGE TO ALL MEMBERS WITH LEVEL @email[1] ***\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "$DATA{'email_message'}\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "$title webmaster\n";
    close(MAIL);

sleep(1);

		}
dbmclose(%Z);

	}

}

$errors = " Email has been sent to <b>$c</b> $title members with rank @email[1]: <br>$DATA{'email_message'}\n";

return $errors;


exit;

}


$errors = " Error, mail value specified is not recognized.\n";

return $errors;


exit;