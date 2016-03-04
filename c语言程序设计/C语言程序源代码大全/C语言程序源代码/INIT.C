void init(void)
{
  int gdrive=EGAVGA,gmode=VGAMED;
  registerbgidriver(EGAVGA_driver);
  initgraph(&gdrive,&gmode,"");
}