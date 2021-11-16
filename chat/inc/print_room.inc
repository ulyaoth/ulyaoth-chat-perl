#!/usr/bin/perl


open(CHAT, "$root/online/rooms/$room.txt");

flock(CHAT,1);

@chatroom = <CHAT>;

close(CHAT);

@c = reverse(@chatroom);

$len = $len - 1;

@b = @c[0..$len];

@chat = reverse(@b);

foreach $line (@chat) {

$line =~ s/^\<!--(([^ >]|\n)*)-->//ig;

$line =~ s/^\s+//ig;

print $line;

next;
} 


if(@sndmsg){

print "<hr>\n@sndmsg";

undef @sndmsg;
}

if($errors ne "") {

print "<hr>\n*** $errors<br>\n";

undef $errors;
}

&check_pm();

sub check_pm {


&chop_private;

       open(FILE,"$root/online/pm/$DATA{'n'}.txt");

                @contents = <FILE>;

 close(FILE);

open(CRASH,"$root/online/pm/$DATA{'n'}.txt");

flock (CRASH,2);

@pri = <CRASH>;

close (CRASH);

$i = 0;

foreach $lin (@pri) {

$i++;

}




if ($i > 0) {

if($i > 25){

#print "<a name=\"b\"></a>\n";

}

print "<hr>\n";

foreach $line(@pri){

@two = split(/\s+/,$line);

$line =~ s/^\<!-- (([^ >]|\n)*) -->//ig;

$line =~ s/\s+\s+/ /ig;
$line =~ s/^\s+//ig;

print $line;

}
}

if($frames eq 'yes'){

#print "<a name=\"b\"></a>\n";

}

}

sub chop_private{

open(PRIVATE,"$root/online/pm/$DATA{'n'}.txt");
flock (PRIVATE,2);
@pri = <PRIVATE>;
close (PRIVATE);

open(PRIVATE,">$root/online/pm/$DATA{'n'}.txt");
flock(PRIVATE,2);

foreach $line (@pri) {
@one = split(/ /,$line);

if ($time-$one[1] > $msg_time) {


}else{
print PRIVATE "$line";

}

}
close(PRIVATE);

}







#################### Print Again just $line number of lines #####################################

@w = reverse(@chatroom);

@s = @w[0..$lines];

@print_again = reverse(@s);

open(PRINTCHAT, ">$root/online/rooms/$room.txt");

flock(PRINTCHAT,2);

print PRINTCHAT @print_again;

close(PRINTCHAT);

return true;

