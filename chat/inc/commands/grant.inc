#!/usr/bin/perl




if ($command eq '/grant' && $level < 1){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";


 return $errors;

exit;

       }



@abuse = split(/\s+/,$DATA{'msg'});

unless(@abuse[1]){

$j = 0;
opendir(DIR, "$root/online/users/");

foreach $u(sort(grep !/^\./, readdir DIR)){

$jj++;
 
$u =~ s/.db//ig;

dbmopen(%USE,"$root/online/users/$u",0777);

if($USE{'level'} ne "granted" && $USE{'level'} < 1){

$j++;

$gr = "$gr || <b>$u</b> ($USE{'ip'}) <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/grant\+$u\"><b>GRANT</b></a>";

		}

dbmclose(%USE);

}

if(!$gr){

$errors = " Syntax: /grant [nick]. Total users online <b>$jj</b>. All users are currently granted.";

}else{

$errors = " Syntax: /grant [nick]. Total users online <b>$jj</b>. Not granted users <b>$j</b>.<br>\n($gr ||)";

}

return $errors;

exit;

}


if(!-e "$root/online/users/@abuse[1]"){
     close(NOTANOP);
     
$errors = " Error, user <b>@abuse[1]</b> not found.";

return $errors;

exit;

            }



dbmopen(%USER,"$root/online/users/@abuse[1]",0777);

$grantedid = $USER{'id'};

$grantroom = $USER{'room'};

if($USER{'level'} >= 1 or $USER{'level'} eq "granted"){

$errors = " Error, <b>@abuse[1]</b> is an Op or already granted.";

dbmclose(%USER);

return $errors;

exit;

}



$USER{'level'} = "granted";

dbmclose(%USER);


open(PRIVE,">>$root/online/pm/@abuse[1].txt");


flock(PRIVE,2);

print PRIVE "<!-- $time --> <b>*** You have been granted by Operator $DATA{'n'}. You can now use double slash commands. For a list please click <a href=$location?n=@abuse[1]&id=$grantedid&room=$grantroom&msg=/help>here</a>.</b><br>\n";


close(PRIVE);




$errors = " User <b>$abuse[1]</b> successfuly granted.";

return $errors;

exit;


        