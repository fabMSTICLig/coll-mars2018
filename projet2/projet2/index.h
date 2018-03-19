
const char MAIN_page[] PROGMEM = R"=====(

<html>
  <head>
    <title>Microcar</title>
    <script>
  var modeEtat = 1;
    function s(u){var x = new XMLHttpRequest();x.open("GET", u, true);x.send(null);}
    function ret(u){return function(e){
                                s(u);
                                e.returnValue = false;
                                return false;
                            }
                    }
    window.addEventListener('load', function(){
        var lf = document.getElementById('lf');
        var rf = document.getElementById('rf');
        var lb = document.getElementById('lb');
        var rb = document.getElementById('rb');
        lf.addEventListener('touchstart', ret("lon"), false);
        lf.addEventListener('touchend', ret("loff"), false);
        rf.addEventListener('touchstart', ret("ron"), false);
        rf.addEventListener('touchend', ret("roff"), false);
        lb.addEventListener('touchstart', ret("lron"), false);
        lb.addEventListener('touchend', ret("loff"), false);
        rb.addEventListener('touchstart', ret("rron"), false);
        rb.addEventListener('touchend', ret("roff"), false);
    
    
        var mode = document.getElementById('mode');
        var col = document.getElementById('col');
        var seuilmin = document.getElementById('seuilmin');
        var seuilmax = document.getElementById('seuilmax');
        seuilmin.addEventListener('touchend', ret("seuilmin"), false);
        seuilmax.addEventListener('touchend', ret("seuilmax"), false);
        col.addEventListener('touchend', ret("col"), false);
    
    mode.addEventListener('touchend', function(){
      if(modeEtat == 1)
      {
        modeEtat = 2;
        mode.innerHTML ="Mode 2";
        ret("mode2")({returnValue:null});
      }
      else
      {
        modeEtat = 1;
        mode.innerHTML ="Mode 1";
        ret("mode1")({returnValue:null});
      }
    
    }, false);
     
    }, false);

    </script>
  </head>
  <body>
  <div>
    <button id="lf" style="width:50%;height:40%;float:left;">LF</button>
    <button id="rf" style="width:50%;height:40%;float:left;">RF</button>
    <button id="lb" style="width:50%;height:40%;float:left;">LB</button>
    <button id="rb" style="width:50%;height:40%;float:left;">RB</button>
    <button id="mode" style="width:20%;height:20%;float:left;">Mode 1</button>
    <button id="col" style="width:20%;height:20%;float:left;">Col</button>
    <button id="seuilmin" style="width:20%;height:20%;float:left;">Seuil Min</button>
    <button id="seuilmax" style="width:20%;height:20%;float:left;">Seuil Max</button>
    </div>
  </body>
</html>

)=====";
