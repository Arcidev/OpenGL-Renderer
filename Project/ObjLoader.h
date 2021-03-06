#pragma once
#include <fstream>
#include <iostream>
#include "Shared\SharedDefines.h"

#define MTL_NOT_DEFINED "MTL NOT DEFINED"

enum ParserProperty
{
    PROPERTY_NOT_DEFINED, // default value

    // textures
    AMBIENT_TEXTURE,
    DIFFUSE_TEXTURE,
    ALPHA_TEXTURE,
    BUMP_MAP,

    // color
    AMBIENT_COLOR,
    DIFFUSE_COLOR,
    SPECULAR_COLOR,

    // MTL
    NEW_MTL,
    USE_MTL,
    SET_MTL_LIB,

    // object
    VERTEX_POSITION,
    TEXTURE_POSITION,
    NORMAL_POSITION,
    TRIANGLE_VALUE
};

typedef map<string, ParserProperty> ParserPropertyMap;

struct Mtl
{
    string ambientTexture; // map_Ka
    string diffuseTexture; // map_Kd
    //string specularTexture; // map_Ks
    //string specularHighLightComponent; // map_Ns
    string alphaTexture; // map_d
    string bumpMap; // map_bump || bump
    //string displacementMap; // disp
    //string stencilDecalMap; // decal
    Vector3f ambientColor; // Ka
    Vector3f diffuseColor; // Kd
    Vector3f specularColor; // Ks
    //float transparency; // Tr

    vector<Triangle> triangles;
};

typedef map<string, Mtl> MTLMap;

class ObjLoader
{
    private:
        static ParserPropertyMap const parserPropertyMap;
        bool m_loadedMtl;
        map<string, Mtl> m_mtlMap;

        ParserProperty GetParserProperty(string const& prop) const;
        bool LoadMtl(string fileName);

    public:
        ObjLoader();
        bool Load(char const* filename);
        MTLMap const& GetMtlMap() const { return m_mtlMap; }

        void PrintLog() const;
};
