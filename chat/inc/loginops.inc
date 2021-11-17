#!/usr/bin/perl

$time = time();

undef $id;

for (0..9) { $id .= pack("C",65+int(rand(25.9999))); }

          my(@addr) = split(/\./, $ENV{'REMOTE_ADDR'});
          my($packed_addr) = pack("C4", $addr[0], $addr[1], $addr[2], $addr[3]);
          my($name, $aliases, $addrtype, $length, @addrs);
          ($name, $aliases, $addrtype, $length, @addrs) = gethostbyaddr($packed_addr, 2);
          $host_name = $name;

if ($host_name eq ''){

$host_name = $ENV{'REMOTE_ADDR'};

}


($ip1,$ip2,$ip3)=split(/\./,$ENV{'REMOTE_ADDR'});

$ip = "$ip1.$ip2.$ip3";

dbmopen(%OPS,"$root/ops/ops/$DATA{'n'}.db",0777);

$ops_acc = $DATA{'n'};

$ops_began = $OPS{'ops_began'};

$ops_months = $OPS{'ops_months'};

$ops_end = $OPS{'ops_end'};

$pa = $OPS{'password'};

$level = $OPS{'level'};

$opsid = $OPS{'id'};


dbmclose(%OPS);



$password = crypt($DATA{'pass'}, "Cd");

if ($pa ne $password){

print "Content-type: text/html\n\n";

$loginerror = "*** Sorry the nickname <b>$DATA{'n'}</b> or the password is not correct, please retype your nick and password and try to login again!";

require "$root/inc/login.inc";

exit;

}

####################################### KICK #################################################

if(-e "$root/online/kicked/$DATA{'n'}.db"){

dbmopen(%KICK,"$root/online/kicked/$DATA{'n'}.db",0777);

$ff = $time - $KICK{'time'};

$time_kick_left = $kicktime - $ff;

$loginerror = " $KICK{'kick'}<center><font color=red>Time left:$time_kick_left.</font></center>";

dbmclose(%KICK);

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

}

#################################################################################################



if(-e "$root/online/banned/$DATA{'n'}.db"){

dbmopen(%BANNED,"$root/online/banned/$DATA{'n'}.db",0777);

$f = $time - $BANNED{'bantime'};

$timeleft = $bantime - $f;


$loginerror = " $BANNED{'ban'}<center><font color=red>Time left:$timeleft.</font></center>";

dbmclose(%BANNED);

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

}


## Suspended


if(-e "$root/suspend/$DATA{'n'}.db"){

dbmopen(%BANNED,"$root/suspend/$DATA{'n'}.db",0777);

$loginerror = " $BANNED{'out'}<center><font color=red>Please contact $title for more information.</font></center>";

dbmclose(%BANNED);

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

}


### expired?

dbmopen(%A,"$root/ops/ops/$DATA{'n'}.db",0777);

($xday,$xmonth,$xyear) = split(/\//,$A{'ops_end'});

$stt = $A{'ops_began'};

dbmclose(%A);

if ($emonth < 10) { $emonth = "0$emonth"; }  

$ssh = $year . $emonth . $day;

if ($xmonth < 10) { $xmonth = "0$xmonth"; }  

if ($xday < 10 && $xday !~ /^0/) { $xday = "0$xday"; }  


$en = $xyear . $xmonth . $xday;

if($ssh > $en){

$loginerror = " *** Ops account <b>$DATA{'n'}</b> expired. Account started on <b>$stt</b> ending <b>$xday\/$xmonth\/$xyear</b>. Current date <b>$day\/$emonth\/$year</b>. Please click <a href=\"\/cgi-bin\/saq\/renewal.cgi\">here</a> to renew.";

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

		}


################################## READ REAL IP ############################################################

print "Content-type: text/html\n";

require "/opt/ulyaoth/chat/cookies/cookie.lib";

&GetCookies('ulyaoth');

&GetCookies('realip');

if($Cookies{'realip'}){

$trace_ip = $Cookies{'realip'};

}else{

&SetCookies('realip',$ENV{'REMOTE_ADDR'});

$teace_ip = $ENV{'REMOTE_ADDR'};

}

################################### USED NICKS ######################################

if($Cookies{'ulyaoth'} =~ /$DATA{'n'}/){

$used_nicks = $Cookies{'ulyaoth'};

$crap = "$Cookies{'ulyaoth'}";

}else{

if(-e "$root/ops/ops/$DATA{'n'}.db"){

$used_nicks = "$Cookies{'ulyaoth'}\!\#$DATA{'n'}\#";

$crap = "$Cookies{'ulyaoth'}\!\#$DATA{'n'}\#";

}else{

$used_nicks = "$Cookies{'ulyaoth'}\!$DATA{'n'}";










$crap = "$Cookies{'ulyaoth'}\!$DATA{'n'}";

}}

&SetCookies('ulyaoth',$crap);


print "\n";
##########################################################################################################



if(-e "$root/online/lastnick/$DATA{'n'}.txt"){

open(LAST,"$root/online/lastnick/$DATA{'n'}.txt");

$ind = <LAST>;

close(LAST);

@last = split(/\|\"\'\|/, $ind);

$DATA{'room'} = @last[1];

$a_nick = $DATA{'n'};

$DATA{'n'} = @last[0];

unlink ("$root/online/users/$lastnick.db");

unlink ("$root/online/lastnick/$DATA{'n'}.txt");

}else{


foreach $bb(@rooms){

if($bb =~ /$DATA{'room'}/i && length($DATA{'room'}) == length($bb)){

$public = 1;

$DATA{'room'} = $bb;


}

}



if($public != 1){

$DATA{'room'} = $firstroom;

}

}



if($a_nick){

dbmopen(%PREF,"$root/opspreferences/$a_nick.db",0777);

}else{

dbmopen(%PREF,"$root/opspreferences/$DATA{'n'}.db",0777);

}



if($PREF{'color'} or $PREF{'font'}){


if($PREF{'color'}){

$cf = "color=\"$PREF{'color'}\"";

$xcolor = $PREF{'color'};

}

if($PREF{'font'}){


$vc = "face=\"$PREF{'font'}\"";

}

$color = "<font $cf $vc>";

}else{

$color = "";

}


if(!$PREF{'ecolor'}){

$ecolor = "";

}else{

$ecolor = $PREF{'ecolor'};

}

if(!$PREF{'nfont'}){

$nyfont = "";

}else{

$nyfont = $PREF{'nfont'};

}


$ops_chatmail = $PREF{'mail_status'};

if($PREF{'mail_inbox'} == 0){

$ops_chatmail = "*** <b>CMAIL</b> Total: <b>0</b>. New: <b>0</b>. Please use /mail [nick] to send.";

}

if(!$PREF{'auto_replay'}){

undef $au;

}else{

$au = $PREF{'auto_replay'};

}

if(!$PREF{'text'}){

$text = "";

}else{

$text = $PREF{'text'};

}


if(!$PREF{'bgcolor'}){

$bgcolor = "";

}else{

$bgcolor = $PREF{'bgcolor'};

}

##



if(!$PREF{'ips_control'}){

$ip_c= "";

}else{

$ip_c = $PREF{'ips_control'};

}



if(!$PREF{'speed'}){

$speed = "15";

}else{

$speed = $PREF{'speed'};

}

if(!$PREF{'wid'}){

$wid = "75";

}else{

$wid = $PREF{'wid'};

}

if(!$PREF{'comment'}){

$comment = "";

}else{

$comment = $PREF{'comment'};

}

if(!$PREF{'intro_msg'}){

undef $intro_m;

}else{

$intro_m = $PREF{'intro_msg'};

}



if(!$PREF{'len'}){


$len = "15";

}else{

$len = $PREF{'len'};

}

## Ip

if(!$PREF{'pref_ip'}){

if($level >= $comm_rank){

$ip = "##$ip##";

}else{


$ip = "#$ip#";

}

}else{

$ip = $PREF{'pref_ip'};

}


#########################

if(!$PREF{'nickname'}){

undef $nickname;

}else{

$nickname = $PREF{'nickname'};

}


#########################################################


if($PREF{'menu'} eq ""){

$menu = "";

}else{

$menu = $PREF{'menu'};

}

if($PREF{'nickcolor'} eq ""){

$nicolor = "";

}else{

$nicolor = $PREF{'nickcolor'};

}



dbmclose(%PREF);



################################################################

# Ops ann


open(ANN,"$root/boards/opsann.txt");

flock(ANN,2);

@opsan = <ANN>;

close(ANN);


foreach $lin(@opsan){

if($a_nick){

open(PA,">>$root/online/pm/$a_nick.txt");

}else{
open(PA,">>$root/online/pm/$DATA{'n'}.txt");


}

flock(PA,2);

print PA "<!-- $time --> $lin<br>\n";

close(PA);


}
#############

#wait list

if($a_nick){

open(W,"$root/wait/$a_nick.txt");



$zz = $a_nick;

}else{

open(W,"$root/wait/$DATA{'n'}.txt");

$zz = $DATA{'n'};
}

flock(W,1);

@waitl = <W>;

close(W);

foreach $i(@waitl){

chop($i);

if(-e "$root/online/users/$i"){

open(P,">>$root/online/pm/$zz.txt");

dbmopen(%PR,"$root/online/users/$i.db",0777);

print P "<!-- $time --> *** User <A HREF=\"javascript:m('$i')\"><B>\*$i\*</b></a> <font size=\"1\" color=\"\#FFFFFF\">i</font>  ($PR{'ip'}) is online.<br>\n";

close(P);

dbmclose(%PR);


              }

}
##############################################################################################

opendir(W,"$root/wait/");

flock(W,2);


@w = readdir(W);

close(W);

foreach $c(@w){



if($c ne '.' && $c ne '..'){

$c =~ s/.txt//ig;

if(-e "$root/online/users/$c"){

open(L,"$root/wait/$c.txt");

flock(L,2);

@j = <L>;

foreach $f(@j){

chop($f);

if($f eq $DATA{'n'}){

open(P,">>$root/online/pm/$c.txt");

flock(P,2);

print P "<!-- $time --> *** User <A HREF=\"javascript:m('$DATA{'n'}')\"><B>\*$DATA{'n'}\*</b></a> <font size=\"1\" color=\"\#FFFFFF\">i</font>  ($ip) logged in.<br>\n";

close(P);



				}
			}

close(L);

		}
	}

}





#######################################################################################################################





dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

undef $USER{'id'};


$USER{'id'} = $id; 

$USER{'nick'} = "<A HREF=\"javascript:m('$DATA{'n'}')\">$DATA{'n'}</a>"; 

$USER{'nickname'} = $nickname; 


if($a_nick){

$USER{'a_nick'} = $a_nick; 

}else{

$USER{'a_nick'} = $DATA{'n'}; 
}


$USER{'room'} = $DATA{'room'}; 


$USER{'opsid'} = $opsid; 

$USER{'referer'} = $ENV{'HTTP_REFERER'}; 

$USER{'ip'} = "$ip"; 

$USER{'wid'} = $wid; 

$USER{'comment'} = $comment; 

if($ENV{'HTTP_VIA'}){

$USER{'proxy'} = "<font color=red>active</font>";

}else{

$USER{'proxy'} = "none";

}

$USER{'usednicks'} = $used_nicks; 

$USER{'auto_replay'} = $au; 

$USER{'intro_msg'} = $intro_m;

$USER{'nickcolor'} = $nicolor;

$USER{'speed'} = $speed; 

$USER{'len'} = $len; 

$USER{'frames'} = $DATA{'frames'}; 


if($level >= 10){

open(LOG,">$root/online/action/$DATA{'n'}.txt");

print LOG "ON";

close(LOG);

$ops_logging = "*** Logging enabled. Clear | Warnings | Kick | Ban.<br>\n";


}


if($level >= 1){

$ann_message = "*** Ops account <b>$ops_acc</b> began on $ops_began for $ops_months month(s). Ending $ops_end.<br>\n$ops_logging

$ops_chatmail<br>\n";

}
$USER{'ann_mess'} = $ann_message;

$USER{'idle'} = $time;

$USER{'online'} = $time;

$USER{'realip'} = $trace_ip;

$USER{'level'} = $level; 

$USER{'bgcolor'} = $bgcolor; 

if(-e "$root/deopped/$DATA{'n'}"){

$USER{'deopped'} = 1;

}

$USER{'text'} = $text; 

$USER{'menu'} = $menu; 

$USER{'ips_control'} = $ip_c;

$USER{'color'} = $color; 

$USER{'xcolor'} = $xcolor;

$USER{'nfont'} = $nyfont;

$USER{'my_time'} = $time;

$USER{'ecolor'} = $ecolor; 

$USER{'opsid'} = $opsid; 

if($a_nick){

$USER{'realnick'} = $a_nick;

$ops_acc = $a_nick;

}else{

$ops_acc = $DATA{'n'};

$USER{'realnick'} = $DATA{'n'};

}

$USER{'fullip'} = $ENV{'REMOTE_ADDR'};


$USER{'user_agent'} = $ENV{'HTTP_USER_AGENT'};

$USER{'host_name'} = $host_name;

if($DATA{'frames'} eq 'yes'){

$USER{'fr'} = "yes";

}


dbmclose(%USER);

$wid = "75";

$speed = "15";

$len = "14";


if($DATA{'room'} eq "Doorstep"){

     $welcome = "$DATA{'n'} trips over the Doorstep!";

}elsif($DATA{'room'} eq "Hot_Tub"){


     $welcome = "$DATA{'n'} does a cannonball into the Hot_Tub!";

}elsif($DATA{'room'} eq "Forest"){

     $welcome = "$DATA{'n'} is chained to a tree in the Forest!";

}elsif($DATA{'room'} eq "20plus"){

     $welcome = "$DATA{'n'} wants to talk to someone their own age!";

}elsif($DATA{'room'} eq "30plus"){




     $welcome = "$DATA{'n'} wants to talk to someone their own age!";

}elsif($DATA{'room'} eq "40plus"){



     $welcome = "$DATA{'n'} wants to talk to someone their own age!";

}elsif($DATA{'room'} eq "Australia"){

     $welcome = "G'Day Mate!";


}elsif($DATA{'room'} eq "Bar"){

     $welcome = "$DATA{'n'} walks in hoping to get drunk!";

}elsif($DATA{'room'} eq "Canada"){

     $welcome = "Welcome, eh!";

}elsif($DATA{'room'} eq "Courtyard"){

     $welcome = "$DATA{'n'} strolls into the Courtyard!";

}elsif($DATA{'room'} eq "CyberSex"){

     $welcome = "$DATA{'n'} is looking for some cyber-luvin!";

}elsif($DATA{'room'} eq "New_Users"){

     $welcome = "$DATA{'n'} is new here and would like to make some friends!";

}elsif($DATA{'room'} eq "Teens"){

     $welcome = "$DATA{'n'} wants to talk to someone their own age!";

}elsif($DATA{'room'} eq "UK"){

     $welcome = "Welcome to the UK!";

}elsif($DATA{'room'} eq "USA"){

     $welcome = "Welcome to the USA!";

}elsif($DATA{'room'} eq "Mexico"){

     $welcome = "Recepción!";

}elsif($DATA{'room'} eq "Quebec"){

     $welcome = "Bienvenue!";

}elsif($DATA{'room'} eq "Germany"){

     $welcome = "Willkommen!";

}elsif($DATA{'room'} eq "Arabia"){

     $welcome = "Salam!";

}elsif($DATA{'room'} eq "Belgium"){

     $welcome = "Welkom!";

}elsif($DATA{'room'} eq "India"){


     $welcome = "Welcome to India!";


}elsif($DATA{'room'} eq "Woods"){



     $welcome = "$DATA{'n'} wanders into the Woods!!!";





}elsif($DATA{'room'} eq "Indonesia"){

     $welcome = "Welcome to Indonesia!";

}elsif($DATA{'room'} eq "Malaysia"){

     $welcome = "Selamat Datang!";

}elsif($DATA{'room'} eq "China"){

     $welcome = "Ni How!";

}elsif($DATA{'room'} eq "Hong_Kong"){

     $welcome = "Nei Ho!";

}elsif($DATA{'room'} eq "Philipines"){

     $welcome = "Mabuhay!";

}elsif($DATA{'room'} eq "Turkey"){

     $welcome = "Selam!";



}elsif($DATA{'room'} eq "Holland"){

     $welcome = "Welkom!";

}else{


$welcome = "Welcome!!!";

}

open(ROOMFILE,">>$root/online/rooms/$DATA{'room'}.txt");

flock(ROOMFILE,2);

print ROOMFILE "<!--servermsg--> *** <B>$DATA{'n'}</B> <font size=\"1\" color=\"\#FFFFFF\">i</font> ($ip) <b>$DATA{'room'}</b> /  $welcome<br>\n";

close(ROOMFILE);



return true;
