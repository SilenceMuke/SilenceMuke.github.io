MathJax = {
  chtml: {
    scale: 1.1,
    matchFontHeight: false
  },
  options: {
    enableMenu: false,
    menuOptions: {
      settings: {
        renderer: 'CHTML',
        scale: 1.1
      }
    }
  }
};

document$.subscribe(() => {
    MathJax.startup.output.clearCache()
    MathJax.typesetClear()
    MathJax.texReset()
    MathJax.typesetPromise()
  })
