#!/usr/local/bin/perl

print "Content-type: text/html\n\n";

<html>
<HEAD>
<title></title>

<BODY>

END

ABC
DEF
GHI
JKL
MNO
PQR
STU
VWX
YZ0-9

@imegs = ("/7up","/acidburn","/alien1","/alien2","/angel1","/angel2","/angel3","/angel4","/angel5","/argh","/argue1","/argue2","/arrow","/as","/baby1","/baby2","/baby3","/baby4","/badbreath","/bah","/balloons","/bang","/bat1","/bat2","/bear1","/bear2","/bee","/bigears","/birthday","/blah","/blush","/bolt","/boom","/boots","/bounce","/bowdown1","/bowdown2","/boxing","/breakface","/burp","/butterfly","/caffine","/car1","/car2","/cat1","/cat2","/chainsaw","/chiapet","/chomp","/clap","/cow","/cowboy","/cry1","/cry2","/cuckoo","/cuddle","/cyclops","/dance1","/darkdemon","/dead1","/dead2","/dead3","/devil1","/devil10","/devil11","/devil2","/devil3","/devil5","/devil6","/devil7","/devil8","/devil9","/dissolve","/dizzy","/dog1","/dog2","/doh","/drool","/drool2","/drown","/drunk","/duck","/duel","/dunno","/eat","/eatme","/evil1","/evil2","/eyebrows","/eyes","/faces","/fish","/flowers","/freak","/freedom","/frog1","/frog2","/funny","/gasp","/gay","/glare","/gotcha","/greedy","/grin1","/grin2","/grr","/gun1","/gun2","/gun3","/gun4","/gun5","/gun6","/gun7","/gun8","/gun9","/hacker","/hammer","/headbang","/heart1","/heart2","/heart3","/heart4","/hehe","/helpme","/heyhey","/hippie","/hostage","/huh","/hybrid","/idea","/jerk","/king","/kiss1","/kiss2","/knowitall","/ko","/kotc","/lick","/lilangel","/lips","/love1","/love2","/love3","/love4","/love5","/love6","/love7","/love8","/love9","/lovestory","/mad","/magicpill","/monkey1","/monkey2","/moon1","/moon2","/moon3","/moose","/munch","/music","/mustache","/nerd","/newbie","/ninja","/no1","/no2","/nobrain","/nod","/nofriends","/nono","/nile","/nuhuh","/omg","/pbth","/peace","/penguin","/phone","/pig","/pikachu","/pirate","/poke1","/poke2","/police","/ponder","/protest","/puke1","/puke2","/puke3","/puke4","/punch","/puppyeyes","/question","/rabbit","/rabies","/rae","/rb","/rock","/rockdevil","/rocket","/rolleyes","/rotfl1","/rotfl2","/rotfl3","/rudolf","/runlikehell","/sad","/santa","/sexy","/shades","/sheepish","/shh","/shout","/shrug1","/shrug2","/sick1","/sick2","/sigh","/skull","/smile","/smoke","/smurf","/snail","/sneeze","/sniffle1","/sniffle2","/snore1","/snore2","/snot","/snowflake","/snowman","/soother","/spank","/star1","/star2","/suspicious","/teeth","/tongue1","/tongue2","/trippy","/trippyangel","/twitch","/ugh","/um","/vamp","/wave1","/wave2","/whip","/wink","/wolf","/worry","/wtf","/yawn","/yell","/yes","/yuk","/yum","/zap","/zorro");


foreach $m (@imegs) {

if ($i == 1) {

if ($m =~ /^\/a/i or $m =~ /^\/b/i $m =~ /^\/c/i) {

push(@new,$m);

}

} elsif ($i == 2) {

if ($m =~ /^\/d/i or $m =~ /^\/e/i $m =~ /^\/f/i) {

push(@new,$m);

}


} elsif ($i == 3) {

if ($m =~ /^\/g/i or $m =~ /^\/h/i $m =~ /^\/i/i) {

push(@new,$m);

}


} elsif ($i == 4) {


if ($m =~ /^\/j/i or $m =~ /^\/k/i $m =~ /^\/l/i) {

push(@new,$m);

}

} elsif ($i == 5) {


if ($m =~ /^\/m/i or $m =~ /^\/n/i $m =~ /^\/o/i) {

push(@new,$m);

}

} elsif ($i == 6) {


if ($m =~ /^\/p/i or $m =~ /^\/q/i $m =~ /^\/r/i) {

push(@new,$m);

}

} elsif ($i == 7) {


if ($m =~ /^\/s/i or $m =~ /^\/t/i $m =~ /^\/u/i) {

push(@new,$m);

}

} elsif ($i == 8) {


if ($m =~ /^\/v/i or $m =~ /^\/w/i $m =~ /^\/x/i) {

push(@new,$m);

}

} elsif ($i == 9) {


if ($m =~ /^\/y/i or $m =~ /^\/z/i $m =~ /^\/\d+/i) {

push(@new,$m);

}


print "<table border=1 width=100%><tr>\n";

foreach $k (@new) {

if($frames eq 'yes'){

$k = "<td width=15% height=\"60\">&nbsp;&nbsp;<a href=\"#b\" onclick=\"parent.frames[1].document.myform.msg.value=parent.frames[1].document.myform.msg.value+' $k ';\"><img src=\"/img$k.gif\" border=0><br>$k</a></td>";


} else {

$k = "<td width=15%>&nbsp;&nbsp;<a href=\"#b\" onclick=\"document.forms[0].msg.value=document.forms[0].msg.value+' $k ';\"><img src=\"/img$k.gif\" border=0></a></td><td width=5%>&nbsp;<a href=\"#b\" onclick=\"document.forms[0].msg.value=document.forms[0].msg.value+' $k ';scroll(1,10000);\">$k</a></td>";

}

printf "%-25s  ",$k;



if ($x % 5 == 0) { print "</tr><tr>\n"; }

 }

print "</tr></table><p>\n";

print "<b>INFO:<br>&nbsp;&nbsp;&nbsp;&nbsp;images are clickable as well as aliases, please be patient for page to load once it loads images will be cached inside your browser's memory and accessing this page will be much easier.</b><p>\n";

print "</body></html>";
exit;