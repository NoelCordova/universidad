<?php
session_start();
include 'connection.php';

if(isset($_SESSION['email'])) {?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <title>Uncle nostalgia</title>
    <link rel="stylesheet" href="css/styles-homeUsuario.css">
</head>
<body>
    <header>
        <nav class="navbar navbar-inverse navbar-static-top" role="navigation">
            <div class="container">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navegacion-fm">
                        <span class="sr-only">Desplegar / Ocultar Menú</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a href="homeUsuario.php" class="navbar-brand">:')</a>
                </div>
                <!-- Inicia menú -->
                <div class="collapse navbar-collapse" id="navegacion-fm">
                    <ul class="nav navbar-nav">
                        <li class="active"><a href="exp.php">Explorar</a></li>
                        <li class="dropdown">
                            <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button">
                            <?php 
                                echo $_SESSION['nickname'];
                            ?>
                            <span class="caret"></span></a>
                            <ul class="dropdown-menu" role="menu">
                                <li><a href="homeUsuario.php"><span class="glyphicon glyphicon-user"></span> Perfil</a></li>
                                <li><a href="logout.php"><span class="glyphicon glyphicon-log-out"></span> Log out</a></li>
                            </ul>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>
    </header>
    <div class="jumbotron">
        <div class="container text-center">
            <h1>Musica para machos de verda'</h1>      
        </div>
    </div>
    <div class="main container">
        <div class="row">
            <div class="disco1 col-sm-12 col-md-4">
                <h4 class="disco">PVRIS - White Noise</h4>
                <a href="#D1" data-toggle="modal"><img src="img/wht.jpg" width="100%"></a>
            </div>
            <div class="disco2 col-sm-12 col-md-4">
                <h4 class="disco">Bring me the Horizon - Sempiternal</h4>
                <a href="#D2" data-toggle="modal"><img src="img/smpt.jpg" width="100%"></a>
            </div>
            <div class="disco3 col-sm-12 col-md-4">
                <h4 class="disco">Royal Blood - Royal Blood</h4>
                <a href="#D3" data-toggle="modal"><img src="img/blood.jpg" width="100%"></a>
            </div>
        </div>
        <br> <br>
        <div class="row">
            <div class="disco1 col-sm-12 col-md-4">
                <h4 class="disco">Ghost BS - Meliora</h4>
                <a href="#D4" data-toggle="modal"><img src="img/meliora.jpg" width="100%"></a>
            </div>
            <div class="disco2 col-sm-12 col-md-4">
                <h4 class="disco">Chevelle - Sci-Fi Crimes</h4>
                <a href="#D5" data-toggle="modal"><img src="img/sci.jpg" width="100%"></a>
            </div>
            <div class="disco3 col-sm-12 col-md-4">
                <h4 class="disco">Paramore - RIOT!</h4>
                <a href="#D6" data-toggle="modal"><img src="img/riot.jpg" width="100%"></a>
            </div>
        </div>
    </div>
    <!-- DISCOS -->
    <div class="modal fade" id="D1">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">PVRIS - White Noise</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://embed.spotify.com/?uri=spotify%3Aalbum%3A7acEEWUWq2GVgeS9tr9cOp" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="D2">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">Bring me the Horizon - Sempiternal</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://embed.spotify.com/?uri=spotify%3Aalbum%3A4dhfdOEUI4tfqwdgouFTQA" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="D3">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">Royal Blood - Royal Blood</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://embed.spotify.com/?uri=spotify%3Aalbum%3A4dhfdOEUI4tfqwdgouFTQA" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="D4">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">Ghost BC - Meliora</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://open.spotify.com/embed/album/74QTwjBLo1eLqpjL320rXX" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="D5">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">Chevelle - Sci-Fi Crimes</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://open.spotify.com/embed/album/4yo38BbmUi80kZOqHlRhNH" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="D6">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">Paramore - RIOT!</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://open.spotify.com/embed/album/3UoOO8m0oxxvUHXUKf3qcZ" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <footer>
        <div class="container">
            <div class="col-xs-12">
                <h5 class="text-center">&#60;/white_noise&#62;</h5>
            </div>
        </div>
    </footer>
</body>
</html>
<?php
}else{
    echo '<script> window.location="index.php"; </script>';
}
?>