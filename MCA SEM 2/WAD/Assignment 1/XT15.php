<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Assignment 1 XT15</title>
</head>
<body>
<?php

$str = "pradip karmakar";
echo "<center>";
echo '<table border = 1 >';

echo "<tr><td>";
echo "trim ";
echo "</td><td>";
echo trim($str,"kar"); 
echo "</td></tr>";

echo "<tr><td>";
echo "rtrim ";
echo "</td><td>";
echo rtrim($str,"kar"); 
echo "</td></tr>";

echo "<tr><td>";
echo "ltrim ";
echo "</td><td>";
echo ltrim($str,"pra"); 
echo "</td></tr>";

echo "<tr><td>";
echo "STR_PAD_LEFT ";
echo "</td><td>";
echo str_pad($str, 30, "*", STR_PAD_LEFT); 
echo "</td></tr>";

echo "<tr><td>";
echo "STR_PAD_BOTH ";
echo "</td><td>";
echo str_pad($str, 30, "*", STR_PAD_BOTH); 
echo "</td></tr>";

echo "<tr><td>";
echo "STR_PAD";
echo "</td><td>";
echo str_pad($str, 30, "*"); 
echo "</td></tr>";

echo "<tr><td>";
echo "lcfirst(Lower case)";
echo "</td><td>"; 
echo lcfirst("Hey siri!");
echo "</td></tr>";

echo "<tr><td>";
echo "ucfirst(Upper case)";
echo "</td><td>"; 
echo ucfirst("hey siri !");
echo "</td></tr>";

echo "<tr><td>";
echo "ucwords";
echo "</td><td>"; 
echo ucwords("Hey siri !");
echo "</td></tr>";


echo "<tr><td>";
echo "Strtolower";
echo "</td><td>"; 
echo Strtolower($str);
echo "</td></tr>";


echo "<tr><td>";
echo "strtoupper";
echo "</td><td>"; 
echo strtoupper($str);
echo "</td></tr>";


echo "<tr><td>";
echo "strrev";
echo "</td><td>"; 
echo strrev($str);
echo "</td></tr>";

echo "<tr><td>";
echo "str_shuffle (ymmv)";
echo "</td><td>"; 
echo str_shuffle($str);
echo "</td></tr>";

echo "<tr><td>";
echo "str_repeat";
echo "</td><td>"; 
echo str_repeat(" P.J.D.A ", 5);
echo "</td></tr>";

$str2 = "Hello World Its Pradip Karmakar";
echo "<tr><td>";
echo "explode";
echo "</td><td>"; 
print_r(explode(' ', $str2, 1));
echo "</td></tr>";

$arr = array('Hello','Wolrd','Its','Pradip','Karmakar');
echo "<tr><td>";
echo "implode";
echo "</td><td>"; 
echo implode("<b>+</b>", $arr);
echo "</td></tr>";

echo "<tr><td>";
echo "strcmp";
echo "</td><td>"; 
echo strcmp("Pradip","pradip");
echo "</td></tr>";

echo "<tr><td>";
echo "strcasecmp";
echo "</td><td>"; 
echo strcasecmp("Pradip","pradip");
echo "</td></tr>";

echo "<tr><td>";
echo "strlen";
echo "</td><td>"; 
echo strlen("Pradip Karmakar");
echo "</td></tr>";

echo "<tr><td>";
echo "strstr";
echo "</td><td>"; 
echo strstr("Pradip Karmakar", " ");
echo "</td></tr>";

echo "<tr><td>";
echo "stristr";
echo "</td><td>"; 
echo stristr("Pradip Karmakar", " K");
echo "</td></tr>";

echo "<tr><td>";
echo "strrstr(true)";
echo "</td><td>"; 
echo strchr("Hello world world!","world",true);
echo "</td></tr>";

echo "<tr><td>";
echo "strchr";
echo "</td><td>"; 
echo strchr("Hello world world!","world");
echo "</td></tr>";

echo "<tr><td>";
echo "strrchr";
echo "</td><td>"; 
echo strrchr("Hello world world!","world");
echo "</td></tr>";


echo "<tr><td>";
echo "strpos";
echo "</td><td>"; 
echo strpos("Ajinkya php, php","php");
echo "</td></tr>";

echo "<tr><td>";
echo "strrpos";
echo "</td><td>"; 
echo strrpos("Ajinkya php, php","php") . "<br>";
echo "</td></tr>";


echo "<tr><td>";
echo "substr_replace";
echo "</td><td>"; 
echo substr_replace("Bobby", 'bob', 0) . "<br>";
echo "</td></tr>";



echo "<tr><td>";
echo "str_replace";
echo "</td><td>"; 
echo str_replace("Pradip", "Supriya", "Pradip Karmakar") . "<br>";
echo "</td></tr>";

echo "</table>";
echo "</center>";

?>
</body>
</html>
