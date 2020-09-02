<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Assignment 1 XT16</title>
    <link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
    <div class="box">
        <form method="POST">
            <div>
                <input type="text" placeholder="Enter Your Name" name="uname" autocomplete="off" required>
            </div>
            <div>
                <input type="text" placeholder="Enter Your Password" name="pass" autocomplete="off" required>
            </div>
            <div>
                <input type="submit" name="submit" class="submit" value="check">   
            </div>
        </form>
        <?php
            if(isset($_POST['submit']))
            {
                if(preg_match("/^[A-Za-z]+[A-Za-z0-9]/", $_POST["uname"]) === 0)
                {
                    echo"Invalid format in UserName";
                    die();
                }
                else{
                    if(preg_match("/[a-zA-Z0-9]+[?!0-9]/", $_POST['pass']) == 0)
                    {
                        echo"Invalid format Of password";
                        die();
                    }
                    else{
                        echo "Username = " . $_POST['uname'] . "<br> Password = " .  $_POST['pass'] ;
                    }
                }
            }
        ?>
    </div>
</body>
</html>
