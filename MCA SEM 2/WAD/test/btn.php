<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Button</title>
    <style>
    body{
            margin: 0;
            background-color:black; 
        }
        .content{
            text-align: center;
            margin: 10% 0 0 0;
        }
        .form_element{
            width: 28%;
            height: 55px;
            border-radius: 5px;
            border: 2px solid aquamarine;
            padding: 10px;
            margin-top: 10px;
            font-size: medium;
        }

        .form_button{
            width: 35%;
            height: 45px;
            border-radius: 5px;
            border: 0px;
            background-color: red;
            margin: 10px 0 20px 0;
            font-weight: bold;
        }

        .form_button:hover{
            cursor: pointer;
            background-color: greenyellow;
        }

    </style>
</head>
<body>
    <div class="content">
        <form method="POST">
            <div>
                <input type="text" name="cap" class="form_element" placeholder="Write Caption"/>
            </div>
            <div>
                <input type="text" name="color" class="form_element" placeholder="Write Color Name"/>
                <br><p style="color:#fff;"><span style="color:red;">* </span>Please Provide Proper Color Name otherwise won't effect.</p>
            </div>
            <div>
                <input type="submit" name="submit" value="submit" class="form_button">
            </div>
        </form>
        <?php
            if(isset($_POST['submit']))
            {
                $caption = $_POST['cap'];
                $color = $_POST['color'];
        ?>
            <div>
                <input type="button" value="<?= $caption; ?>" class="form_button" style="background-color:<?= $color; ?>">
            </div>
        <?php
            }
        ?>
    </div>
</body>
</html>