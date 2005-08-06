#include "resource.h"
#include "../shared-code/install.h"

#define KINSHORT "BigBro"
#define KINNAME "Big Brother"
#define VERSION "1.5.1"

BOOL Install(void)
{
STRING dPath = strFETCH_REG_KEY(HKEY_LOCAL_MACHINE,"Software\\Klever Group",KINSHORT "Path");
STRING kPath = strFETCH_REG_KEY(HKEY_LOCAL_MACHINE,"Software\\Klever Group","KINPath");
LPCSTR qPath = ((LPCSTR)dPath)?(LPCSTR)dPath:(((LPCSTR)kPath)?(LPSTR)kPath:"C:\\Program Files\\Klever\\Nothings");
STRING path = REQUESTPATH("  " KINNAME " " VERSION,"\nEnter destination path:",qPath);
	if(!path)
		return NULL;

#ifdef	K_ANNED
STRING sysDir(_MAX_PATH);
	GetSystemDirectory(sysDir,_MAX_PATH);
	INSTALLFILE("mfc42.dl_",sysDir,"mfc42.dll");
#endif

	MAKE_PATH(path);
STRING shortPath = GET_SHORT_PATH(path);
	if(!shortPath){
		MessageBox(NULL,"Failed to install " KINNAME " " VERSION " in specified directory",NULL,MB_ICONERROR|MB_OK);
		return FALSE;
	}

	if(!(
		INSTALLFILE("bigbro.ex_",path,"bigbro.exe") &&
		INSTALLFILE("bigbro.hl_",path,"bigbro.hlp") && 
		INSTALLFILE("bigbro.cn_",path,"bigbro.cnt")
	)){
		MessageBox(NULL,"Failed to install " KINNAME " " VERSION " in specified directory",NULL,MB_ICONERROR|MB_OK);
		return FALSE;
	}
	ADDMENU("Klever Group",KINNAME,path,"bigbro.exe");

	strSET_REG_KEY(HKEY_LOCAL_MACHINE,"Software\\Klever Group",KINSHORT "Path",path);
	strSET_REG_KEY(HKEY_LOCAL_MACHINE,"Software\\Klever Group","KINPath",path);

FILE* inf=CREATE_INF_FILE(path,KINSHORT ".INF");
	if(!inf){
		MessageBox(NULL,"Failed to install " KINNAME " " VERSION,NULL,MB_ICONERROR|MB_OK);
		return FALSE;
	}
	INF_FILE_HEADER(inf);
	INF_FILE_SECTION(inf,"Uninstall");
	fprintf(inf,"AddReg=kFiles\nDelReg=kReg\nUpdateInis=kMenu\n");
	INF_FILE_SECTION(inf,"kFiles");
	INF_REMOVE_ROOT(inf,KINSHORT "Files",path);
	INF_REMOVE_FILE(inf,KINSHORT "Files","bigbro.exe");
	INF_REMOVE_HELP_FILE(inf,KINSHORT "Files","bigbro");
	INF_REMOVE_FILE(inf,KINSHORT "Files","bigbro.inf");
	INF_FILE_SECTION(inf,"kReg");
	INF_UNINSTALL_REG(inf,KINSHORT);
	INF_FILE_SECTION(inf,"kMenu");
	INF_MENU_GROUP(inf,1,"Klever Group");
	INF_MENU_ITEM(inf,1,KINNAME);
	fclose(inf);

	REG_UNINSTALL_COMMAND(KINSHORT,"Klever " KINNAME " " VERSION,shortPath,KINSHORT".INF","Uninstall");
    REG_UNINSTALL_ICON(KINSHORT,path,"bigbrother.exe",0);
    REG_UNINSTALL_COMMENT(KINSHORT,"Klever Big brother");
    REG_UNINSTALL_VERSION(KINSHORT,VERSION);
    REG_UNINSTALL_LOCATION(KINSHORT,path);
    REG_UNINSTALL_PUBLISHER(KINSHORT,"Klever Group");
    REG_UNINSTALL_URLS(KINSHORT,"http://www.klever.net/","http://kin.klever.net/bigbrother/");

	MessageBox(NULL,KINNAME" " VERSION " installed successfully, you may now run it from 'Programs/Klever Group' menu or remove it using Control Panel Add/Remove Programs applet."," Rejoice!",MB_ICONINFORMATION|MB_OK);

	return TRUE;
}
