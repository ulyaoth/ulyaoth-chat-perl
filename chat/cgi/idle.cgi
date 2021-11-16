#!/usr/bin/perl

use DB_File;

######################## IDLE USERS ###############################################

opendir(DIR, "$root/online/users/");

foreach $entry(sort(grep !/^\./, readdir DIR)){

                $entry =~ s/.db//ig;

dbmopen(%USER,"$root/online/users/$entry",0777);

$check = $time - $USER{'idle'};

$rnicky = $USER{'realnick'}; 

dbmclose(%USER);
               
if ($check > $idle){

$kill_user = $entry;

do "$root/inc/kill_user.inc";

undef $kill_user;


        } 



}

##########################################################################################


############################### NO PROXY IDLE ############################################

open(PROXY, "$root/online/noproxy/proxy.txt");

$proxy = <PROXY>;

close(PROXY);

$pr_time = $time - $proxy;


if($pr_time > 1200){

unlink ("$root/online/noproxy/proxy.txt");


}

#########################################################################################

##################################### BAN IDLE ##########################################

opendir(BANNED, "$root/online/banned/");


@banned = readdir (BANNED);

      closedir(BANNED);

    foreach $ban (sort @banned){

 if($ban ne '.' && $ban ne '..'){

                $ban =~ s/.db//;

dbmopen(%BANNED,"$root/online/banned/$ban",0777);


$f = $time - $BANNED{'bantime'};

dbmclose(%BANNED);

$timet = $bantime - $f;

if($timet < 1){


unlink ("$root/online/banned/$ban");


} 

}}

#################################################################################################################

########################################### KICK IDLE ###########################################################


opendir(KLICKED, "$root/online/kicked/");


@kicked = readdir (KLICKED);

      closedir(KLICKED);

    foreach $kick (sort @kicked){

 if($kick ne '.' && $kick ne '..'){

                $kick =~ s/.db//;

dbmopen(%K,"$root/online/kicked/$kick",0777);

$fkick = $time - $K{'time'};

dbmclose(%K);

$timek = $kicktime - $fkick;

if($timek < 1){


unlink ("$root/online/kicked/$kick");


} 

}}
########################################################################################################








#################################### CLEAR EMPTY ROOMS ###############################################################

opendir(READROOMS, "$root/online/rooms/");

@allrooms = readdir (READROOMS);

      closedir(READROOMS);

    foreach $n (sort @allrooms) {

       if ($n ne '.' && $n ne '..') {

$n =~ s/.txt//;

&get_users($n);

if ($b == 0){

unlink ("$root/online/rooms/$n.txt");

unlink ("$root/online/locked/$n.txt");
 
            }
      }
}




sub get_users{

$b = 0;

my($rclear) = @_;

opendir(ROOMUSERS, "$root/online/users/");


@room_users = readdir (ROOMUSERS);

      closedir(ROOMUSERS);

    foreach $roomuser (sort @room_users){

if($roomuser ne '.' && $roomuser ne '..'){

                $roomuser =~ s/.db//;

dbmopen(%USER,"$root/online/users/$roomuser",0777);

if($USER{'room'} eq $rclear){

$b++;

} 


dbmclose(%USER);

                 }
       }



foreach $s(@rooms){

if($rclear eq $s){

$b = 1;
		}
	}


return $b;
}


return true;