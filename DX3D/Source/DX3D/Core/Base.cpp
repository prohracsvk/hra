#include "DX3D/Core/Base.h"
#include "DX3D/Core/Common.h"
#include "DX3D/Core/Logger.h"
using namespace dx3d;


dx3d::Base::Base(const BaseDesc& desc): m_logger(desc.logger)
{
}

dx3d::Base::~Base()
{
}

Logger& dx3d::Base::getLogger()  noexcept
{
	return m_logger;
}
