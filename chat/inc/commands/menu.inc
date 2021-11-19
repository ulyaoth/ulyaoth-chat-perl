#!/usr/bin/perl



if($menu == 1){


dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

undef $USER{'menu'};

dbmclose(%USER);

$errors = " Slower mode, standard room menu, only affects non-frames, use /menu to switch back.";

$menu = "";

return $errors;

return $menu;

exit 0;
}

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'menu'} = 1;

dbmclose(%USER);

$errors = " Faster mode, click on room to change, only affects non-frames, use /menu to switch back.";

$menu = 1;

return $menu;


return $errors;

return true;