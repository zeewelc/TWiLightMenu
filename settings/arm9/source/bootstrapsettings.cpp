
#include "common/inifile.h"
#include "common/bootstrappaths.h"
#include "common/dsimenusettings.h"
#include "bootstrapsettings.h"
#include <string.h>

BootstrapSettings::BootstrapSettings()
{
    debug = false;
	logging = false;
	romreadled = BootstrapSettings::ELEDNone;
	preciseVolumeControl = false;
    soundFreq = false;
}

void BootstrapSettings::loadSettings()
{
    CIniFile bootstrapini(BOOTSTRAP_INI);

    // UI settings.
   	debug = bootstrapini.GetInt("NDS-BOOTSTRAP", "DEBUG", debug);
	logging = bootstrapini.GetInt("NDS-BOOTSTRAP", "LOGGING", logging);
	if (isDSiMode()) {
		romreadled = bootstrapini.GetInt("NDS-BOOTSTRAP", "ROMREAD_LED", romreadled);
		preciseVolumeControl = bootstrapini.GetInt("NDS-BOOTSTRAP", "PRECISE_VOLUME_CONTROL", preciseVolumeControl);
	}
	soundFreq = bootstrapini.GetInt( "NDS-BOOTSTRAP", "SOUND_FREQ", soundFreq);

}

void BootstrapSettings::saveSettings()
{
    CIniFile bootstrapini(BOOTSTRAP_INI);

    // UI settings.
    bootstrapini.SetInt("NDS-BOOTSTRAP", "DEBUG", debug);
	bootstrapini.SetInt("NDS-BOOTSTRAP", "LOGGING", logging);
	if (isDSiMode()) {
		bootstrapini.SetInt("NDS-BOOTSTRAP", "ROMREAD_LED", romreadled);
		bootstrapini.SetInt("NDS-BOOTSTRAP", "PRECISE_VOLUME_CONTROL", preciseVolumeControl);
	}
	bootstrapini.SetInt( "NDS-BOOTSTRAP", "COLOR_MODE", ms().colorMode);
	bootstrapini.SetInt( "NDS-BOOTSTRAP", "SOUND_FREQ", ms().soundFreq);
    bootstrapini.SaveIniFile(BOOTSTRAP_INI);
}
