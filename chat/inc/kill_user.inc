#!/usr/bin/perl

unlink ("$root/online/pm/$kill_user.txt");

dbmopen(%KILL,"$root/online/users/$kill_user.db",0777);

if($KILL{'level'} >= 1){

unlink ("$root/online/lastnick/$KILL{'realnick'}.txt");

unlink ("$root/online/action/$kill_user.txt");

open(TIME,"$root/time/$KILL{'realnick'}.dat");

flock(TIME,2);

$q = <TIME>;

close(TIME);

$my_time = $time - $KILL{'my_time'};

$new_time = $q + $my_time;

open(TIM,">$root/time/$KILL{'realnick'}.dat");

flock(TIM,1);

print TIM $new_time;

close(TIM);

}

dbmclose(%KILL);

unlink ("$root/online/users/$kill_user.db");

return true;

exit;
