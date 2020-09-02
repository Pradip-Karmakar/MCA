<?php

class Dataclass
{
    
	private $conn;


    public function __construct()
    {
       $this->conn=mysqli_connect("localhost","root","","bookmaster") or die('connection Failed');
    }
    public function getConn()
    {
        return $this->conn;
    }

    public function saveRecord($query)
    {
    	$res=mysqli_query($this->conn,$query);
	    return $res;
    }
}

$dc = new Dataclass();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exam Program</title>
    <style>
        body{
            margin: 0;
            background-color:aqua; 
        }
        .box{
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
    <div class="box">
        <form method="POST">
            <div>
                <input type="text" id="book_id" name="book_id" placeholder="Enter Book Id" class="form_element" required>
            </div>
            <div>
                <input type="text" id="book_title" name="book_title" placeholder="Enter Book Title" class="form_element" required>
            </div>
            <div>
                <input type="number" id="book_price" name="book_price" placeholder="Enter Book price" class="form_element" required>
            </div>
            <div id="btn">
                <input type="submit" name="submit" class="form_button" id="submit">
            </div>
        </form>
    </div>
    <?php

    if(isset($_POST['submit']))
    {
        $id = $_POST['book_id'];
        $title = $_POST['book_title'];
        $price = $_POST['book_price'];
        $save = "insert into book(bookid,title,price) values('$id','$title','$price')";
		if ($dc->saveRecord($save))
		{
			$msg = "Book Record Insert Successfully";
		}
		else
		{
			$msg = "Book Record Insert Failed";
		}
    ?>

    <div style="text-align: center;">
        <h2> <?= $msg; ?> </h2>
    </div>
    
    <?php
    }
    ?>
</body>
</html>