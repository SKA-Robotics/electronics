<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head>
        <meta charset="utf-8" />
        <title>Bill of Materials</title>
      </head>
      <body>
        <table style="font:8pt Segoe UI" border="1" cellspacing="0" cellpadding="1" bgcolor="#FFFFFF">
          <thead style="font:bold; background-color:#C0C0C0">
            <tr valign="top">
              <xsl:for-each select="/GRID/COLUMNS/COLUMN">
                <td align="center">
                  <xsl:attribute name="width">
                    <xsl:value-of select="@Width" />
                  </xsl:attribute>
                  <xsl:value-of select="@Caption" />
                </td>
              </xsl:for-each>
            </tr>
          </thead>
          <xsl:for-each select="/GRID/ROWS/ROW">
            <tr valign="top">
              <td align="left">
                <xsl:value-of select="@Name" />
                <xsl:if test="@Name[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Designator" />
                <xsl:if test="@Designator[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Footprint" />
                <xsl:if test="@Footprint[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Center_X_mm_" />
                <xsl:if test="@Center_X_mm_[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Center_Y_mm_" />
                <xsl:if test="@Center_Y_mm_[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Mounting_Technology" />
                <xsl:if test="@Mounting_Technology[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@PartNumber" />
                <xsl:if test="@PartNumber[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Layer" />
                <xsl:if test="@Layer[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Rotation" />
                <xsl:if test="@Rotation[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Description" />
                <xsl:if test="@Description[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Part_Number" />
                <xsl:if test="@Part_Number[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@MountingTechnology" />
                <xsl:if test="@MountingTechnology[.='']">&#160;</xsl:if>
              </td>
              <td align="left">
                <xsl:value-of select="@Mount" />
                <xsl:if test="@Mount[.='']">&#160;</xsl:if>
              </td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>