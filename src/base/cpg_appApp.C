#include "cpg_appApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<cpg_appApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

cpg_appApp::cpg_appApp(InputParameters parameters) : MooseApp(parameters)
{
  cpg_appApp::registerAll(_factory, _action_factory, _syntax);
}

cpg_appApp::~cpg_appApp() {}

void
cpg_appApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"cpg_appApp"});
  Registry::registerActionsTo(af, {"cpg_appApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
cpg_appApp::registerApps()
{
  registerApp(cpg_appApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
cpg_appApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cpg_appApp::registerAll(f, af, s);
}
extern "C" void
cpg_appApp__registerApps()
{
  cpg_appApp::registerApps();
}
