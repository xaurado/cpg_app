//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "cpg_appTestApp.h"
#include "cpg_appApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<cpg_appTestApp>()
{
  InputParameters params = validParams<cpg_appApp>();
  return params;
}

cpg_appTestApp::cpg_appTestApp(InputParameters parameters) : MooseApp(parameters)
{
  cpg_appTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

cpg_appTestApp::~cpg_appTestApp() {}

void
cpg_appTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  cpg_appApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"cpg_appTestApp"});
    Registry::registerActionsTo(af, {"cpg_appTestApp"});
  }
}

void
cpg_appTestApp::registerApps()
{
  registerApp(cpg_appApp);
  registerApp(cpg_appTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
cpg_appTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cpg_appTestApp::registerAll(f, af, s);
}
extern "C" void
cpg_appTestApp__registerApps()
{
  cpg_appTestApp::registerApps();
}
