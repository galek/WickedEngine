#ifndef _RESOURCEBUFFER_MAPPING_H_
#define _RESOURCEBUFFER_MAPPING_H_

// Slot matchings:
////////////////////////////////////////////////////

// Unordered Access Resources (u slot):

#define UAVSLOT_TILEFRUSTUMS						0
#define UAVSLOT_LIGHTINDEXCOUNTERHELPER				0
#define UAVSLOT_LIGHTINDEXLIST_OPAQUE				1
#define UAVSLOT_LIGHTINDEXLIST_TRANSPARENT			2
#define UAVSLOT_LIGHTGRID_OPAQUE					3
#define UAVSLOT_LIGHTGRID_TRANSPARENT				4
#define UAVSLOT_DEBUGTEXTURE						7


// Textures (t slot):

#define TEXSLOT_DEPTH				0
#define TEXSLOT_LINEARDEPTH			1

#define TEXSLOT_GBUFFER0			2
#define TEXSLOT_GBUFFER1			3
#define TEXSLOT_GBUFFER2			4
#define TEXSLOT_GBUFFER3			5
#define TEXSLOT_GBUFFER4			6

#define TEXSLOT_ENV_GLOBAL			7
#define TEXSLOT_ENV0				8
#define TEXSLOT_ENV1				9
#define TEXSLOT_ENV2				10
#define TEXSLOT_DECALATLAS			11

#define TEXSLOT_SHADOWARRAY_2D		12
#define TEXSLOT_SHADOWARRAY_CUBE	13

#define TEXSLOT_VOXELRADIANCE		14

#define TEXSLOT_ONDEMAND0			15
#define TEXSLOT_ONDEMAND1			16
#define TEXSLOT_ONDEMAND2			17
#define TEXSLOT_ONDEMAND3			18
#define TEXSLOT_ONDEMAND4			19
#define TEXSLOT_ONDEMAND5			20
#define TEXSLOT_ONDEMAND6			21
#define TEXSLOT_ONDEMAND7			22
#define TEXSLOT_ONDEMAND8			23
#define TEXSLOT_ONDEMAND9			24
#define TEXSLOT_ONDEMAND_COUNT	(TEXSLOT_ONDEMAND9 - TEXSLOT_ONDEMAND0 + 1)

#define TEXSLOT_LIGHTGRID			25

// Ondemand textures are 2d textures and declared in shader globals, these can be used independently in any shader
#define TEXSLOT_UNIQUE0				26
#define TEXSLOT_UNIQUE1				27

#define TEXSLOT_COUNT		TEXSLOT_UNIQUE1

// Structured Buffers (t slot):
#define SBSLOT_TILEFRUSTUMS			25
#define SBSLOT_LIGHTINDEXLIST		26
#define SBSLOT_LIGHTARRAY			27

// Skinning:
#define SKINNINGSLOT_IN_VERTEX_POS	0
#define SKINNINGSLOT_IN_VERTEX_NOR	1
#define SKINNINGSLOT_IN_VERTEX_WEI	2
#define SKINNINGSLOT_IN_VERTEX_BON	3
#define SKINNINGSLOT_IN_BONEBUFFER	4

#define SKINNINGSLOT_OUT_VERTEX_POS	0
#define SKINNINGSLOT_OUT_VERTEX_NOR	1
#define SKINNINGSLOT_OUT_VERTEX_PRE	2



///////////////////////////
// Helpers:
///////////////////////////

// CPP:
/////////

#define STRUCTUREDBUFFER_BINDSLOT __StructuredBuffer_BindSlot__
// Add this to a struct to match that with a bind slot:
#define STRUCTUREDBUFFER_SETBINDSLOT(slot) static const int STRUCTUREDBUFFER_BINDSLOT = (slot);
// Get bindslot from a struct which is matched with a bind slot:
#define STRUCTUREDBUFFER_GETBINDSLOT(structname) structname::STRUCTUREDBUFFER_BINDSLOT



// Shader:
//////////

// Automatically binds resources on the shader side:

#define RAWBUFFER(name,slot) ByteAddressBuffer name : register(t ## slot)
#define RWRAWBUFFER(name,slot) RWByteAddressBuffer name : register(u ## slot)

#define TYPEDBUFFER(name, type, slot) Buffer< type > name : register(t ## slot)
#define RWTYPEDBUFFER(name, type, slot) RWBuffer< type > name : register(u ## slot)

#define STRUCTUREDBUFFER(name, type, slot) StructuredBuffer< type > name : register(t ## slot)
#define RWSTRUCTUREDBUFFER(name, type, slot) RWStructuredBuffer< type > name : register(u ## slot)
#define ROVSTRUCTUREDBUFFER(name, type, slot) RasterizerOrderedStructuredBuffer< type > name : register(u ## slot)


#define TEXTURE1D(name, type, slot) Texture1D< type > name : register(t ## slot);
#define TEXTURE1DARRAY(name, type, slot) Texture1DArray< type > name : register(t ## slot);
#define RWTEXTURE1D(name, type, slot) RWTexture1D< type > name : register(u ## slot);

#define TEXTURE2D(name, type, slot) Texture2D< type > name : register(t ## slot);
#define TEXTURE2DMS(name, type, slot) Texture2DMS< type > name : register(t ## slot);
#define TEXTURE2DARRAY(name, type, slot) Texture2DArray< type > name : register(t ## slot);
#define RWTEXTURE2D(name, type, slot) RWTexture2D< type > name : register(u ## slot);
#define ROVTEXTURE2D(name, type, slot) RasterizerOrderedTexture2D< type > name : register(u ## slot);

#define TEXTURECUBE(name, type, slot) TextureCube< type > name : register(t ## slot);
#define TEXTURECUBEARRAY(name, type, slot) TextureCubeArray< type > name : register(t ## slot);

#define TEXTURE3D(name, type, slot) Texture3D< type > name : register(t ## slot);
#define RWTEXTURE3D(name, type, slot) RWTexture3D< type > name : register(u ## slot);
#define ROVTEXTURE3D(name, type, slot) RasterizerOrderedTexture3D< type > name : register(u ## slot);

#endif // _RESOURCEBUFFER_MAPPING_H_
