#include <ScenarioClass.h>
#include "Body.h"

bool SideExt::isNODSidebar()
{
	auto const PlayerSideIndex = ScenarioClass::Instance->PlayerSideIndex;
	if (auto const pSide = SideClass::Array->GetItemOrDefault(PlayerSideIndex)) {
		if (auto const pData = SideExt::ExtMap.Find(pSide)) {
			return !pData->Sidebar_GDIPositions;
		}
	}
	return PlayerSideIndex;
}

DEFINE_HOOK(0x6A5090, SidebarGDIPositions1, 0x5)
{
	R->EAX(SideExt::isNODSidebar());
	return 0x6A509B;
}

DEFINE_HOOK(0x652EAB, SidebarGDIPositions2, 0x6)
{
	R->EAX(SideExt::isNODSidebar());
	return 0x652EB7;
}

DEFINE_HOOK(0x6A51E9, SidebarGDIPositions3, 0x6)
{
	DWORD& SidebarClass__OBJECT_HEIGHT = *reinterpret_cast<DWORD*>(0xB0B500);
	SidebarClass__OBJECT_HEIGHT = 0x32;

	bool pos = SideExt::isNODSidebar();
	R->ESI(pos);
	R->EDX(pos);
	return 0x6A5205;
}

// power bar
DEFINE_HOOK(0x63FB5D, SidebarGDIPositions4, 0x6)
{
	R->EAX(SideExt::isNODSidebar());
	return 0x63FB63;
}

// power bar tooltip
DEFINE_HOOK(0x6403DF, SidebarGDIPositions5, 0x6)
{
	R->ESI(SideExt::isNODSidebar());
	return 0x6403E5;
}
