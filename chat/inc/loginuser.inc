#!/usr/bin/perl

foreach $bb(@rooms){

if($bb =~ /$DATA{'room'}/i && length($DATA{'room'}) == length($bb)){

$public = 1;

$DATA{'room'} = $bb;

}

}

if($public != 1){

$DATA{'room'} = $firstroom;

}





for (0..9) { $id .= pack("C",65+int(rand(25.9999))); }

          my(@addr) = split(/\./, $ENV{'REMOTE_ADDR'});
          my($packed_addr) = pack("C4", $addr[0], $addr[1], $addr[2], $addr[3]);
          my($name, $aliases, $addrtype, $length, @addrs);
          ($name, $aliases, $addrtype, $length, @addrs) = gethostbyaddr($packed_addr, 2);
          $host_name = $name;

if ($host_name eq ''){

$host_name = $ENV{'REMOTE_ADDR'};

}

###################################################################################

############################# KICK KICK ###########################################

$kicked_usr_agent = $ENV{'HTTP_USER_AGENT'};

$ffull_ip = $ENV{'REMOTE_ADDR'};

$kicked_usr_agent =~ s/[^\w]//g;

$ffull_ip =~ s/[^\w]//g;

$kkicked = "$kicked_usr_agent$ffull_ip";

if(-e "$root/online/kicked/$kkicked"){

dbmopen(%KICK,"$root/online/kicked/$kkicked.db",0777);

$ff = $time - $KICK{'time'};

$time_kick_left = $kicktime - $ff;

$tim = $time_kick_left;


$m = $tim / 60;

$h = $m / 60;

($h,$sdfgsfg)=split(/\./,$h);

$h =~ s/[^\w]//g;

$x = $h * 60;

$m = $m - $x;

($m,$sdfgs)=split(/\./,$m);


$m =~ s/[^\w]//g;

$c = $m * 60;

$k = $h * 3600;

$w = $k + $c;


$s = $tim - $w;


if($h < 10){

$h = "0$h";

}

if($m < 10){

$m = "0$m";

}

if($s < 10){

$s = "0$s";

}

$onlinet = "$h:$m:$s";




$loginerror = " $KICK{'kick'}<center><font color=red>Time left:$onlinet.</font></center>";

dbmclose(%KICK);

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

}

undef $onlinet;
######################################################################################

######################################### COOKIES STUFF ################################

################################## READ REAL IP ############################################################

print "Content-type: text/html\n";

require "/srv/ulyaoth/chat/cookies/cookie.lib";



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


($ip1,$ip2,$ip3)=split(/\./,$ENV{'REMOTE_ADDR'});

$ip = "$ip1.$ip2.$ip3";

($iiip1,$iiip2,$iiip3)=split(/\./,$trace_ip);

$tip = "$iiip1.$iiip2.$iiip3";



################# INVALID NICK ###################################################

foreach $word(@badwords){

if($DATA{'n'} =~ /$word/i){

 $loginerror = " *** Invalid nickname.";

require "$root/inc/login.inc";

exit;


}
}


if($DATA{'n'} =~ /ulyaoth/i){

$loginerror = " *** Invalid nickname.";

require "$root/inc/login.inc";

exit;

}


################## CHECK BAN ########################################


if(-e "$root/online/banned/$ip.db"){

dbmopen(%BANNED,"$root/online/banned/$ip.db",0777);

$f = $time - $BANNED{'bantime'};

$timeleft = $bantime - $f;


$tim = $timeleft;


$m = $tim / 60;

$h = $m / 60;

($h,$sdfgsfg)=split(/\./,$h);

$h =~ s/[^\w]//g;

$x = $h * 60;

$m = $m - $x;

($m,$sdfgs)=split(/\./,$m);


$m =~ s/[^\w]//g;

$c = $m * 60;

$k = $h * 3600;

$w = $k + $c;


$s = $tim - $w;


if($h < 10){

$h = "0$h";

}

if($m < 10){

$m = "0$m";

}

if($s < 10){

$s = "0$s";

}

$onlinet = "$h:$m:$s";


$loginerror = " $BANNED{'ban'}<center><font color=red>Time left:$onlinet.</font></center>";

dbmclose(%BANNED);


require "$root/inc/login.inc";

exit;

}
undef $onlinet;
############### CHECK COOKIE/BAN #####################################

if(-e "$root/online/banned/$tip.db"){

dbmopen(%BANNED,"$root/online/banned/$tip.db",0777);

$f = $time - $BANNED{'bantime'};

$timeleft = $bantime - $f;


$tim = $timeleft;


$m = $tim / 60;

$h = $m / 60;

($h,$sdfgsfg)=split(/\./,$h);

$h =~ s/[^\w]//g;

$x = $h * 60;

$m = $m - $x;

($m,$sdfgs)=split(/\./,$m);


$m =~ s/[^\w]//g;

$c = $m * 60;

$k = $h * 3600;

$w = $k + $c;


$s = $tim - $w;


if($h < 10){

$h = "0$h";

}

if($m < 10){

$m = "0$m";

}

if($s < 10){

$s = "0$s";

}

$onlinet = "$h:$m:$s";





$loginerror = " $BANNED{'ban'}<center><font color=red>Time left:$onlinet.</font></center>";

dbmclose(%BANNED);


require "$root/inc/login.inc";

exit;

}

undef $onlinet;
######################################################################








############################### NO PROXY ########################################

if($ENV{'HTTP_VIA'} && -e "$root/online/noproxy/proxy.txt"){

$loginerror = " *** Error , all proxies are currently blocked. Ip address <b>$ENV{'REMOTE_ADDR'}</b> or host <b>$host_name</b> is listed as a proxy server.<p> <center><b>PLEASE TURN OFF YOUR PROXY AND TRY TO LOGIN AGAIN!</b>.";



require "$root/inc/login.inc";

exit;

}

##############################################################################################

opendir(W,"$root/wait/");

flock(W,2);

@w = readdir(W);

closedir(W);

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

print P "<!-- $time --> *** User <A HREF=\"javascript:m('$DATA{'n'}')\"><B>\*$DATA{'n'}\*</b></a><font size=\"1\" color=\"\#FFFFFF\">i</font>  ($ip) logged in.<br>\n";

close(P);


					}
			}


close(L);

		}
	}

}





#######################################################################################################################


open(ANN,"$root/boards/uann.txt");

flock(ANN,2);

@an = <ANN>;

close(ANN);

foreach $lin(@an){

open(PA,">>$root/online/pm/$DATA{'n'}.txt");

flock(PA,2);

print PA "<!-- $time --> $lin<br>\n";

close(PA);


}



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'id'} = $id; 

$USER{'nick'} = "<A HREF=\"javascript:m('$DATA{'n'}')\">$DATA{'n'}</a>"; 

$USER{'room'} = $DATA{'room'}; 

$USER{'opsid'} = "user"; 

$USER{'referer'} = $ENV{'HTTP_REFERER'};

$USER{'ip'} = $ip; 

$USER{'wid'} = "75"; 

if($ENV{'HTTP_VIA'}){

$USER{'proxy'} = "<font color=red>active</font>";

}else{


$USER{'proxy'} = "none";

}

$USER{'realip'} = $trace_ip; 

$USER{'speed'} = "15"; 

$USER{'len'} = "15"; 

$USER{'usednicks'} = $used_nicks; 

$USER{'frames'} = $DATA{'frames'}; 

$USER{'level'} = "0"; 


$USER{'opsid'} = "user"; 

$USER{'realnick'} = $DATA{'n'};

$USER{'fullip'} = $ENV{'REMOTE_ADDR'};

$USER{'idle'} = $time;

$USER{'online'} = $time;

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


}elsif($DATA{'room'} eq "Woods"){


     $welcome = "$DATA{'n'} wanders into the Woods!!!";


}elsif($DATA{'room'} eq "Germany"){

     $welcome = "Willkommen!";

}elsif($DATA{'room'} eq "Arabia"){

     $welcome = "Salam!";

}elsif($DATA{'room'} eq "Belgium"){

     $welcome = "Welkom!";

}elsif($DATA{'room'} eq "India"){

     $welcome = "Welcome to India!";

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



return $len;

return $wid;

return $speed;






