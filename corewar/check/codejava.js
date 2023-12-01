//Foncion Collapse Expand

function Toggle(nom)
{
  var bloc_name = 'expand_'+nom;
  var button_name = 'button_'+nom;

  if (document.getElementById)
  {
    Button = document.getElementById (button_name);
    DivBloc = document.getElementById (bloc_name);
    Display = true;
  }

  else if (document.all)
  {
    Button = document.all[button_name];
    DivBloc = document.all[bloc_name];
    Display = true;
  }

  else if (document.layers)
  {
    Button = document.layers[button_name];
    DivBloc = document.layers[bloc_name];
    Display = true;
  }

  else
  {
    Display = false;
  }

  if (Display)
  {
    if (DivBloc.style.display == "none")
    {
      Button.src = "img/exp_min.gif";
      Button.alt = "Hide";
      DivBloc.style.display = "";
    }
    else
    {
      Button.src = "img/exp_max.gif";
      Button.alt = "Open";
      DivBloc.style.display = "none";
    }
  }

}