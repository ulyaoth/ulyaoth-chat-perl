#!/usr/bin/perl

open(CHATROOM,"$root/online/rooms/$room.txt");

flock(CHATROOM,2);

@chatroom = <CHATROOM>;

close(CHATROOM);

$f = 1;

foreach $key (@chat) {

$f++;

}

@c = reverse(@chatroom);

$len = $len - 1;

@b = @c[0..$len];

@chat = reverse(@b);

print @chat;

if ($errors ne ''){

print "<hr color=\"#3300FF\">*** $errors<br>";

}

&check_pm;



$r = 1;
       

if ($f > $lines){


 open(RE,">$root/online/rooms/$room.txt");
              
flock(RE,2);

  foreach $linee (@chat){

 if ($r == 1){
 
}else{

print RE $linee;

 }

   $r++;
                }
                close(RE);
        } 



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

if($i > 5){
print "<a name=\"b\"></a>\n";
}

print "<hr color=\"#3300FF\">\n";

foreach $line(@pri){

@two = split(/\s+/,$line);

$line =~ s/@two[0]//ig;
$line =~ s/@two[1]//ig;
$line =~ s/@two[2]//ig;
$line =~ s/\s+\s+/ /ig;
$line =~ s/^\s+//ig;

print $line;

}
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


return true;