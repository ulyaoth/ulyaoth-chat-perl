#!/usr/bin/perl



if ($command eq '/acc' && $level < $admin_rank){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



@acc = split(/\s+/, $DATA{'msg'});

unless(@acc[1]){

$errors = " Syntax: /acc [nick]";

return $errors;

exit;

}


if(!-e "$root/ops/ops/@acc[1].db"){
        close(CHECKOP);

$errors = " Error, account <b>@acc[1]</b> does not exist.";

 return $errors;

       exit;

       }

dbmopen(%D,"$root/ops/ops/@acc[1].db",0777);


if($D{'level'} > $max_comm_rank && $level < $staff_rank){


dbmclose(%D);


$errors = " Error, this action is not allowed.";

 return $errors;

       exit;

}

dbmclose(%D);




###############

print "Content-type: text/html\n\n";


print "<head><title>Ulyaoth Chat</title>\n</head>\n\n<body><center><b>Please be careful, changing this information can affect the Operator's account.</b></center><p><p>\n";

print "<center><table width=500><tr><td>\n<FORM METHOD=\"POST\" NAME=\"msg\" ACTION=\"$location\">\n";

dbmopen(%P,"$root/ops/ops/@acc[1].db",0777);

print "<b>Nickname: <font color=\"red\">@acc[1]</font></b><p>\n";

print "<INPUT type=\"text\" name=\"opslevel\" maxlength=14 value=\"$P{'level'}\"> - Rank<p>\n";

print "$P{'ops_began'} - Started<p>\n";

print "$P{'ops_end'} - End<p>\n";

print "<INPUT type=\"text\" name=\"opssid\" maxlength=14 value=\"$P{'id'}\"> - Ops id<p>\n";

print "<INPUT type=\"text\" name=\"opspass\" maxlength=14 value=\"$P{'realpassword'}\"> - Password<p>\n";

print "<INPUT type=\"text\" name=\"opsname\" maxlength=80 value=\"$P{'name'}\"> - Name<p>\n";

print "<INPUT type=\"text\" name=\"opssurname\" maxlength=80 value=\"$P{'surname'}\"> - Surname<p>\n";

print "<INPUT type=\"text\" name=\"opscountry\" maxlength=80 value=\"$P{'country'}\"> - Country<p>\n";

print "<INPUT type=\"text\" name=\"opszip\" maxlength=14 value=\"$P{'zipcode'}\"> - Zip code<p>\n";

print "<INPUT type=\"text\" name=\"opsstreet\" maxlength=80 value=\"$P{'street'}\"> - Street<p>\n";

print "<INPUT type=\"text\" name=\"opsphone\" maxlength=80 value=\"$P{'phone'}\"> - Phone number<p>\n";

print "<INPUT type=\"text\" name=\"opsemail\" maxlength=60 value=\"$P{'email'}\"> - Email address<p>\n";

print "<INPUT type=\"hidden\" name=\"opsnick\" value=\"@acc[1]\"><p>\n";


dbmclose(%P);

print "</table>\n\n";

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$DATA{'id'}\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"msg\" VALUE=\"/editacc\">\n";

print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$DATA{'room'}\">\n";

print "<br><INPUT TYPE=SUBMIT VALUE=\"  UPDATE  \"> || <b><a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room\"> ABORT</a><b><br>";

print "</body>\n";


################


exit;