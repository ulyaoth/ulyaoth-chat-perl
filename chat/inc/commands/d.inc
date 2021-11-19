#!/usr/bin/perl




foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}


@d = split(/\s+/,$DATA{'msg'});


$z = 0;

foreach $key(@d){

if($key =~ /<img/){

$z++;
}
}



if(!@d[1]){

$errors = " Syntax: /d [message].";



return $errors;



exit;



}



if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}



foreach $yay(@badwords){

if($DATA{'msg'} =~ /$yay/i && !-e "$root/online/locked/$room.txt"){


$errors = " Error sending message, not allowed.";

return $errors;

exit;


          }

}



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

#########

$flood = $time - $USER{'msg_flood'};

if($USER{'flooder_time'} < $time){

if($flood < 2 && length($DATA{'msg'}) >= 100){

$no_flood = 15;

}elsif($flood < 2 && length($DATA{'msg'}) < 100){

$no_flood = 6;

}elsif($flood > 2 && $flood < 6){

$no_flood = 4;

}

$USER{'flooder_time'} = $time + $no_flood;

}


$no_flood = $USER{'flooder_time'} - $time;


if($no_flood && $DATA{'msg'}){

$errors = " Error, posting too fast, please wait <b>$no_flood</b> seconds and try reposting your message.";

}


$USER{'msg_flood'} = $time;



dbmclose(%USER);


if($errors){

return $errors;

exit;

}


$dmsg = $DATA{'msg'};

$DATA{'msg'} =~ s/^\/d//;

$DATA{'msg'} =~ s/^\s+//;

#################################################################


open(D, ">>$root/online/rooms/$room.txt");

flock(D,2);

$nickname =~ s/\]//ig;

$nickname =~ s/\[//ig;

if($nickname){

print D "<!--$realnick--> $scolor* $nickname$DATA{'n'}</a><font size=\"1\" color=\"$iback\">i</font> ";

}else{

print D "<!--$realnick--> $scolor* <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> ";


}

undef @com;

@com = split(/\s+/,$DATA{'msg'});

$i = -1;
##################################################################

foreach $one (@com) {

$i++;

$eff1 = substr(@com[$i], 0, 3);
$eff2 = substr(@com[$i], 3, 3);
$eff3 = substr(@com[$i], 6, 3);
$eff4 = substr(@com[$i], 7, 3);
$eff5 = substr(@com[$i], 10, 3);
$eff6 = substr(@com[$i], 13, 3);
$eff7 = substr(@com[$i], 0, 7);

$HEX = substr(@com[$i], 1, 6);

if ($HEX  =~ /[\W]/){

$HEX = "000000";

}

if ($eff1 eq "/it" || $eff1 eq "/un" || $eff1 eq "/bl" || $eff1 eq "/mk" || $eff1 eq "/al" || $eff1 eq "/sp" || $eff1 eq "/su" || $eff1 eq "/st") {$THE_REST = substr(@com[$i],3);}
elsif ($eff2 eq "/it" || $eff2 eq "/un" || $eff2 eq "/bl" || $eff2 eq "/mk" || $eff2 eq "/al" || $eff2 eq "/sp" || $eff2 eq "/su" || $eff2 eq "/st") {$THE_REST = substr(@com[$i],6);}
elsif ($eff3 eq "/it" || $eff3 eq "/un" || $eff3 eq "/bl" || $eff3 eq "/mk" || $eff3 eq "/al" || $eff3 eq "/sp" || $eff3 eq "/su" || $eff3 eq "/st") {$THE_REST = substr(@com[$i],9);}
elsif ($eff4 eq "/it" || $eff4 eq "/un" || $eff4 eq "/bl" || $eff4 eq "/mk" || $eff4 eq "/al" || $eff4 eq "/sp" || $eff4 eq "/su" || $eff4 eq "/st") {$THE_REST = substr(@com[$i],10);}
elsif ($eff5 eq "/it" || $eff5 eq "/un" || $eff5 eq "/bl" || $eff5 eq "/mk" || $eff5 eq "/al" || $eff5 eq "/sp" || $eff5 eq "/su" || $eff5 eq "/st") {$THE_REST = substr(@com[$i],13);}
elsif ($eff6 eq "/it" || $eff6 eq "/un" || $eff6 eq "/bl" || $eff6 eq "/mk" || $eff6 eq "/al" || $eff6 eq "/sp" || $eff6 eq "/su" || $eff6 eq "/st") {$THE_REST = substr(@com[$i],16);}

else{$THE_REST = "@com[$i]";}

########################################################################################################
###STRIKETHROUGH###
if ($eff1 eq "/st" && $THE_REST ne "" || $eff2 eq "/st" && $THE_REST ne "" || $eff3 eq "/st" && $THE_REST ne "" || $eff4 eq "/st" && $THE_REST ne "" || $eff5 eq "/st" && $THE_REST ne "" || $eff6 eq "/st" && $THE_REST ne ""){
if ($eff1 eq "/st"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/st"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/st"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/st"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/st"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/st"){@com[$i] =~ s/$eff6//;}
$st1 = "<strike>";
$st2 = "</strike>";
}else{ 
$st1 = "";
$st2 = "";
}

###SUPERSCRIPT###
if ($eff1 eq "/sp" && $THE_REST ne "" || $eff2 eq "/sp" && $THE_REST ne "" || $eff3 eq "/sp" && $THE_REST ne "" || $eff4 eq "/sp" && $THE_REST ne "" || $eff5 eq "/sp" && $THE_REST ne "" || $eff6 eq "/sp" && $THE_REST ne ""){
if ($eff1 eq "/sp"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/sp"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/sp"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/sp"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/sp"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/sp"){@com[$i] =~ s/$eff6//;}
$sp1 = "<sup>";
$sp2 = "</sup>";
}else{ 
$sp1 = "";
$sp2 = "";
}
###SUBSCRIPT###
if ($eff1 eq "/su" && $THE_REST ne "" || $eff2 eq "/su" && $THE_REST ne "" || $eff3 eq "/su" && $THE_REST ne "" || $eff4 eq "/su" && $THE_REST ne "" || $eff5 eq "/su" && $THE_REST ne "" || $eff6 eq "/su" && $THE_REST ne ""){
if ($eff1 eq "/su"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/su"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/su"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/su"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/su"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/su"){@com[$i] =~ s/$eff6//;}
$su1 = "<sub>";
$su2 = "</sub>";
}else{ 
$su1 = "";
$su2 = "";
}
###--MK--###
if ($eff1 eq "/mk" && $THE_REST ne "" || $eff2 eq "/mk" && $THE_REST ne "" || $eff3 eq "/mk" && $THE_REST ne "" || $eff4 eq "/mk" && $THE_REST ne "" || $eff5 eq "/mk" && $THE_REST ne "" || $eff6 eq "/mk" && $THE_REST ne ""){
if ($eff1 eq "/mk"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/mk"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/mk"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/mk"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/mk"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/mk"){@com[$i] =~ s/$eff6//;}
$mkwidth = 200 - length($IN{'msg'});
$mk1 = "<MARQUEE STYLE=\"{vertical-align: bottom}\" WIDTH=$mkwidth>";
$mk2 = "</marquee>";
}else{ 
$mk1 = "";
$mk2 = "";
}
###--AL--###
if ($eff1 eq "/al" && $THE_REST ne "" || $eff2 eq "/al" && $THE_REST ne "" || $eff3 eq "/al" && $THE_REST ne "" || $eff4 eq "/al" && $THE_REST ne "" || $eff5 eq "/al" && $THE_REST ne "" || $eff6 eq "/al" && $THE_REST ne ""){
if ($eff1 eq "/al"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/al"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/al"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/al"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/al"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/al"){@com[$i] =~ s/$eff6//;}
$alwidth = 200 - length($DATA{'msg'});
$al1 = "<MARQUEE STYLE=\"{vertical-align: bottom}\" BEHAVIOR=ALTERNATE WIDTH=$alwidth>";
$al2 = "</marquee>";
}else{ 
$al1 = "";
$al2 = "";
}


###ITALIC###
if ($eff1 eq "/it" && $THE_REST ne "" || $eff2 eq "/it" && $THE_REST ne "" || $eff3 eq "/it" && $THE_REST ne "" || $eff4 eq "/it" && $THE_REST ne "" || $eff5 eq "/it" && $THE_REST ne "" || $eff6 eq "/it" && $THE_REST ne ""){
if ($eff1 eq "/it"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/it"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/it"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/it"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/it"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/it"){@com[$i] =~ s/$eff6//;}
$it1 = "<i>";
$it2 = "</i>";
}else{ 
$it1 = "";
$it2 = "";
}
###UNDERLINED###
if ($eff1 eq "/un" && $THE_REST ne "" || $eff2 eq "/un" && $THE_REST ne "" || $eff3 eq "/un" && $THE_REST ne "" || $eff4 eq "/un" && $THE_REST ne "" || $eff5 eq "/un" && $THE_REST ne "" || $eff6 eq "/un" && $THE_REST ne ""){
if ($eff1 eq "/un"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/un"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/un"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/un"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/un"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/un"){@com[$i] =~ s/$eff6//;}
$un1 = "<u>";
$un2 = "</u>";
}else{ 
$un1 = "";
$un2 = "";
}


###BLINKING###
if ($eff1 eq "/bl" && $THE_REST ne "" || $eff2 eq "/bl" && $THE_REST ne "" || $eff3 eq "/bl" && $THE_REST ne "" || $eff4 eq "/bl" && $THE_REST ne "" || $eff5 eq "/bl" && $THE_REST ne "" || $eff6 eq "/bl" && $THE_REST ne ""){
if ($eff1 eq "/bl"){@com[$i] =~ s/$eff1//;}
elsif($eff2 eq "/bl"){@com[$i] =~ s/$eff2//;}
elsif($eff3 eq "/bl"){@com[$i] =~ s/$eff3//;}
elsif($eff4 eq "/bl"){@com[$i] =~ s/$eff4//;}
elsif($eff5 eq "/bl"){@com[$i] =~ s/$eff5//;}
elsif($eff6 eq "/bl"){@com[$i] =~ s/$eff6//;}
$bl1 = "<blink>";
$bl2 = "</blink>";
}else{ 
$bl1 = "";
$bl2 = "";
}

###HEX_COLOR###
if ($eff7 eq "/$HEX" && length(@com[$i]) > 7 && $eff1 ne "/bl" && $eff1 ne "/it" && $eff1 ne "/un" && $eff1 ne "/mk" && $eff1 ne "/al" && $eff1 ne "/sp" && $eff1 ne "/su" && $eff1 ne "/st"){
@com[$i] =~ s/\/$HEX//; 
$hex1 = "<font color=\"#$HEX\">"; 
$hex2 = "</font>";
}else{
$hex1 = ""; $hex2 = "";
}

print D "$st1$sp1$su1$mk1$al1$hex1$bl1$un1$it1@com[$i]$it2$un2$bl2$hex2$mk2$al2$sp2$su2$st2 ";

}

print D "$ecolor<br>\n";

close(D);


dbmopen(%USER, "$root/online/users/$DATA{'n'}.db", 0777);


$USER{'lastmsg'} = $dmsg;



dbmclose(%USER);





return true;