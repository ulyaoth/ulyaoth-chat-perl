#!/usr/bin/perl


if($level < $staff_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



@app = split(/\s+/, $DATA{'msg'});


@app[1] =~ s/[^\w]//g;


@app[1] = substr(@app[1],0,12);


if(!@app[1]){

$errors = " Syntax: /add [code].";

return $errors;

exit;

}




if(!-e "$root/app/@app[1]"){

$errors = " Error, application with code <b>@app[1]</b><font size=\"1\" color=\"$iback\">i</font> does not exist.";

return $errors;

exit;

}



dbmopen(%US,"$root/app/@app[1]",0777);

$application = $US{'application'};

dbmclose(%US);


if(-e "$root/ops/ops/$application"){

unlink ("$root/app/@app[1]");


$errors = " Error, this application seems to be too old as someone already got Ops account with nickname <b>$application</b>. This application will be deleted now.";

return $errors;

exit;
}


rename("$root/app/@app[1]","$root/ops/ops/$application");


$errors = " Account <b>$application</b><font size=\"1\" color=\"$iback\">i</font> successfuly added in Ops database.";

return $errors;

exit;








