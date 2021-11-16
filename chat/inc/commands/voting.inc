#!/usr/bin/perl

if($level < $admin_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}

@b = split(/\s+/, $DATA{'msg'});


if(@b[1] eq "reset"){

$w = 0;

opendir(BOOT,"$root/vote/");

@dirlists = readdir(BOOT);

closedir(BOOT);

foreach $i(@dirlists){

if($i ne '.' && $i ne '..'){

$w++;

unlink ("$root/vote/$i");

	}
}

$errors = " Voting system directory has been reseted. Total <b>$w</b> file(s) erased. Running month ($amonth).";
        
return $errors;

exit;

}



if(!@b[2]){

$errors = " Syntax: /voting mr [nick], /voting ms [nick],  /voting reset.";
        
return $errors;

exit;

}


if(@b[1] ne "mr" && @b[1] ne "ms"){

$errors = " Syntax: /voting mr [nick], /voting ms [nick], /voting reset.";
        
return $errors;

exit;

}


if(!-e "$root/ops/ops/@b[2]"){

$errors = " Error, can not find operator <b>@b[2]</b> in database. Winner must be an operator.";
        
return $errors;

exit;

}

if(@b[1] eq "mr"){

open(MR,">$root/boards/mr.txt");

flock(MR,2);

print MR @b[2];

close(MR);

$errors = " Operator <b>@b[2]</b> has been set as mr $title for a month of $amonth.";
        
return $errors;

exit;

}

if(@b[1] eq "ms"){

open(MR,">$root/boards/ms.txt");

flock(MR,2);

print MR @b[2];

close(MR);

$errors = " Operator <b>@b[2]</b> has been set as ms $title for a month of $amonth.";
        
return $errors;

exit;

}
















