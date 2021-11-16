#!/usr/bin/perl  
 
$root = '/opt/ulyaoth/chat';

$firstroom = "welcome";  


 

@my_rooms = ("Bahrain","Belgium","Brazil","Canada","Doorstep","Egypt","England","France","Friends","Germany","Greece","Global","Hawaii","Hong_Kong","Hot_Tub","International","India","Indonesia","Iraq","Jordan","KSA","Kuwait","Lebanon","Malaysia","Mexico","MiddleEast","Netherlands","New_Users","Oman","Pakistan","Philippines","Qatar","Syria","Turkey","UAE","Yemen","Vietnam");  


$sendmail = "/usr/lib/sendmail";



@rooms = sort(@my_rooms);  

@rooms = ("welcome",@rooms);  

$entrytitle = "Ulyaoth Chat - please login";  

$title = "chat.ulyaoth.com";

$webmaster = "webmaster\@ulyaoth.com";

$version = ".:: Ulyaoth chat server 1.0 ::.";  

$location = 'bin.cgi';  

$msg_time = "200";  

$kicktime = "600";  

$bantime = "7200"; 

 ############## RANKS ####################  

$max_ops_rank = "100";  

$comm_rank = "120";  

$max_comm_rank = "170";  

$staff_rank = "180";  

$max_staff_rank = "190";  

$admin_rank = "200";  

########################################  

$idle = "700";  

$lines = "50"; 

$onload = "onLoad=\"window.status='$version';\"";  

@cmds = ("/im","/delacc","/clean","/expired","/rooms","/sban","/ncolor","/nfont","/font","/mute","/stats","/ips","/chk","/voting","/intro","/email2","/email","/ublock","/friends","/friends2","/auto","/vote","/box","//smiles","//brb","//bye","//chat","//cry","//fight","//flower","//fond","//hate","//heart","//hug","//kiss","//later","//leaving","//love","//luck","//mabrook","//mad","//miss","//salam","//shake","//sheeshah","//shy","//sleepy","//sorry","//surprise","//thank","//wave","//welcome","//wsalam","//yell","/warn","/colorbox","/send","/send2","/time","/account2","/account","/uann","/opsann","/sms","/sms2","/icq2","/icq","/grant","//al","//mk","//sp","//su","//st","/callcomm","/mops","/musers","/opsmail","/ip","/reop","/restore","/wait","/roomann","/suspend","/suspendlist","/commlist","/editacc","/record","/lev","/opslist","/acc","//it","//bl","//un","/add","/deoplist","/deop","/images","/vabuse","/report","/dir","/bbclear","/commbbclear","/vcomm","/comm","/abuse","/img","/link","/rose","//b","//r","//g","//y","//w","//bo","/igmail","/mkick","/editann","/ann","/delmail","/mail","/logs","/noproxy","/rose5","/clearbuffer","/clear","/read","/post","/ig","/lock","/unlock","/d","/comment","/quit","/msg","/join","/ops","/bottom","/frames","/whoall","/whois","/who","/color","/pic","/wid","/len","/pref","/bg","/text","/speed","/msg","m","/m","/ban","/unban","/kick","/id","/unban","/changerooms","/menu","/forward","/fl","/list","/summon","/null","/dosummonstuff","//fade","//fade3","/help","/nick","/reboot","/away","/sb");  

$time = time();  


@months = ('January','February','March','April','May','June','July','August','September','October','November','December');  @days = ('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday');  

($sec,$min,$hour,$day,$month,$year,$day2) = (localtime(time))[0,1,2,3,4,5,6];  


if ($sec < 10) { $sec = "0$sec"; }  

if ($min < 10) { $min = "0$min"; }  


if ($hour < 10) { $hour = "0$hour"; }  


if ($day < 10) { $day = "0$day"; }  


$year += "1900";  $weekday = $days[$day2];              

$amonth = $months[$month];   

$fulltime = "$weekday, $amonth $day, $year, $hour:$min:$sec";   

$emonth = $month + 1; 

$time_file = "$year.$day.$emonth";    


$banlogs = "/srv/ulyaoth/chat/public/banlogs/$time_file";   


#images



@imegs = ("/7up","/acidburn","/alien1","/alien2","/angel1","/angel2","/angel3","/angel4","/angel5","/argh","/argue1","/argue2","/arrow","/as","/baby1","/baby2","/baby3","/baby4","/badbreath","/bah","/balloons","/bang","/bat1","/bat2","/bear1","/bear2","/bee","/bigears","/birthday","/blah","/blush","/bolt","/boom","/boots","/bounce","/bowdown1","/bowdown2","/boxing","/breakface","/burp","/butterfly","/caffine","/car1","/car2","/cat1","/cat2","/chainsaw","/chiapet","/chomp","/clap","/cow","/cowboy","/cry1","/cry2","/cuckoo","/cuddle","/cyclops","/dance1","/darkdemon","/dead1","/dead2","/dead3","/devil1","/devil10","/devil11","/devil2","/devil3","/devil5","/devil6","/devil7","/devil8","/devil9","/dissolve","/dizzy","/dog1","/dog2","/doh","/drool","/drool2","/drown","/drunk","/duck","/duel","/dunno","/eat","/eatme","/evil1","/evil2","/eyebrows","/eyes","/faces","/fish","/flowers","/freak","/freedom","/frog1","/frog2","/funny","/gasp","/gay","/glare","/gotcha","/greedy","/grin1","/grin2","/grr","/gun1","/gun2","/gun3","/gun4","/gun5","/gun6","/gun7","/gun8","/gun9","/hacker","/hammer","/headbang","/heart1","/heart2","/heart3","/heart4","/hehe","/helpme","/heyhey","/hippie","/hostage","/huh","/hybrid","/idea","/jerk","/king","/kiss1","/kiss2","/knowitall","/ko","/kotc","/lick","/lilangel","/lips","/love1","/love2","/love3","/love4","/love5","/love6","/love7","/love8","/love9","/lovestory","/mad","/magicpill","/monkey1","/monkey2","/moon1","/moon2","/moon3","/moose","/munch","/music","/mustache","/nerd","/newbie","/ninja","/no1","/no2","/nobrain","/nod","/nofriends","/nono","/nile","/nuhuh","/omg","/pbth","/peace","/penguin","/phone","/pig","/pikachu","/pirate","/poke1","/poke2","/police","/ponder","/protest","/puke1","/puke2","/puke3","/puke4","/punch","/puppyeyes","/question","/rabbit","/rabies","/rae","/rb","/rock","/rockdevil","/rocket","/rolleyes","/rotfl1","/rotfl2","/rotfl3","/rudolf","/runlikehell","/sad","/santa","/sexy","/shades","/sheepish","/shh","/shout","/shrug1","/shrug2","/sick1","/sick2","/sigh","/skull","/smile","/smoke","/smurf","/snail","/sneeze","/sniffle1","/sniffle2","/snore1","/snore2","/snot","/snowflake","/snowman","/soother","/spank","/star1","/star2","/suspicious","/teeth","/tongue1","/tongue2","/trippy","/trippyangel","/twitch","/ugh","/um","/vamp","/wave1","/wave2","/whip","/wink","/wolf","/worry","/wtf","/yawn","/yell","/yes","/yuk","/yum","/zap","/zorro");


## words filtered in private messages and private rooms and public rooms

@nonowords = ("bravo",",opschat","falconchat","friendsway","arabfun","halachat","arabtalk","emaratzone","relaychat","socko","arabiastar","arabiarose","arabia-star","arabia-rose","arabia_rose","arabia_star","abudhabi2000","uaetalk","chatsyria","htc1","hypermart","hawkchat","uaetears", '\d+\.\d+\.\d+\.\d+',"heartchat","alamak","a1amak");



##words filtered in public rooms






@badwords = ("DM","Du Ma","Du Me","Con Cac","Lon Bu","Bu Lon","Bu Cac","Mut Cac","Lon Thui","Lon To","Cac To","Cac Bu","Dit Me","Do Cho De","Di Me","du ma","du me","bravo","opschat","falconchat","friendsway","arabfun","halachat","arabtalk","emaratzone","relaychat","socko","arabiastar","arabiarose","arabia-star","arabia-rose","arabia_rose","arabia_star","abudhabi2000","uaetalk","chatsyria","htc1","hypermart","heartchat","hawkchat","f+_*u+_*k|f+_*u+_*c|p+_*h+_*u+_*c|f+_*u+_*c+_*k|c+_*u+_*n+_*t|w+_*h+_*o+_*r+_*e|s+_*[li1]+_*u+_*t|b+_*[li1]+_*t+_*c+_*h|b+_*a+_*s+_*t+_*a+_*r+_*d|a+_*s+_*s+_*h+_*o+_*[li1]+_*e|c+_*u+_*m|f+_*a+_*g|f+_*a+_*g+_*g+_*o+_*t|n+_*[li1]+_*g+_*g+_*e+_*r");



return true;