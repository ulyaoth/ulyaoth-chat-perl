#!/usr/bin/perl


open(PRIVET,">>$root/online/pm/$DATA{'n'}.txt");

flock(PRIVE,2);

print PRIVET "<!-- $time --> *** Whoa , <b>$summoner</b> has opened a vortex and you've been sucked through to the <b>$summonroom</b> dimension!<br>\n";

close(PRIVET);


open(OLDROOM,">>$root/online/rooms/$room.txt");

flock(OLDROOM,2);

print OLDROOM "<!--servermsg--> *** <B>$DATA{'n'}</B> has been magically summoned away by <b>$summoner</b> to room <b>$summonroom</b>.<br>\n";

close(OLDROOM);

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'room'} = $summonroom;

undef $USER{'summoner'};

undef $USER{'summonroom'};

dbmclose(%USER);

$room = $summonroom;

open(NEWROOM,">>$root/online/rooms/$room.txt");

flock(NEWROOM,2);

print NEWROOM "<!--servermsg--> *** <B>$DATA{'n'}</B> has been summoned to <b>$room</b> by <b>$summoner</b>.<br>\n";

close(NEWROOM);

undef $summoner;

undef $summonroom;

if($frames eq 'yes'){

$mkframe = 1;

return $mkframe;

}

return $room;

return true;